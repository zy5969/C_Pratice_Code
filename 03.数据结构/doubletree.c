#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26

int nodecnt = 0;
typedef struct Node{
    int flag;
    struct Node *next[N];
}Node;

Node *getnode(){
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(Node *) * N);
    nodecnt++;
    return p;
}

int insert(Node *root, char *s){
    Node *p = root;
    for(int i = 0; s[i]; i++){
        int ind = s[i] - 'a';
        if(p->next[ind] == NULL) p->next[ind] = getnode();
        p = p->next[ind];
    }
    p->flag = 1;
    return 1;
}

void output(Node *root, int x, char *arr){
    if(root == NULL) return ;
    arr[x] = '\0';
    if(root->flag) printf("%s\n", arr);
    for(int i = 0; i < N; i++){
        arr[x] = i + 'a';
        output(root->next[i], x + 1, arr);
    }
    return ;
}

void clear(Node *p){
    if(p == NULL) return ;
    for(int i = 0; i < N; i++){
        clear(p->next[i]);
    }
    free(p);
    return ;
}

//双数组字典树
typedef struct Double{
    int base, check;
}Double;

//base值获取
void baseval(Node *root, int x, Double *arr){
    int base = 1, flag = 0;//定义base为1，从1开始判断是否冲突
    while(!flag){
        flag = 1;
        //遍历当前节点每条边
        for(int i = 0; i < N && flag; i++){
            //边为空值，继续向下找存在的边
            if(root->next[i] == NULL) continue;
            //边对应的check值为0时，没有冲突，base值可用
            if(arr[base + i].check == 0) continue;
            else flag = 0;//发生冲突，flag置为0
        }
        if(flag) break;
        base += 1;//flag为0时更新base值继续判断每条边
    }
    //x,对应base值为当前base值
    arr[x].base = base;
    return ;
}

//当前树转换为双数组字典树，返回最大编号
int transdouble(Node *root, int x, Double *arr){
    if(root == NULL) return 1;//为空时直接返回1
    int maxind = x;//取最大编号为传入的x值，x,节点编号
    //节点独立成词时，check取负值
    if(root->flag) arr[x].check = -arr[x].check;
    baseval(root, x, arr);//获取base值
    //记录check值，父节点编号
    for(int i = 0; i < N; i++){
        if(root->next[i] == NULL) continue;
   //更新check数组，arr[x].base + i，当前节点映射的子节点编号
        arr[arr[x].base + i].check = x;
    }
    //转化为双数组
    for(int j = 0; j < N; j++){
        if(root->next[j] == NULL) continue;
        //转换当前子节点，返回最大编号传递给y
        int y = transdouble(root->next[j], arr[x].base + j, arr);
        if(y > maxind) maxind = y; //记录最大下标值
    }
    return maxind;
}

int search(Double *tree, char *str){
    int p = 1;//根节点下标由1开始
    for(int i = 0; str[i]; i++){
        //判断对应子节点父亲是否为其本身，
        //tree[p].base + (str[i] - 'a')子节点下标
        if(abs(tree[tree[p].base + (str[i] - 'a')].check) != p) return 1;
        	//p的值更新节点下标
        p = tree[p].base + str[i] - 'a';
    }
    //check值小于0时独立成词
    return tree[p].check < 0;
}

int main() {
	int n;
    char str[1000] = {0};
    Node *root = getnode();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        insert(root, str);
    }
    Double *arr = (Double *)malloc(sizeof(Double) * nodecnt * N);
    memset(arr, 0, sizeof(Double) * nodecnt * N);
    int cnt = transdouble(root, 1, arr);
    int size1 = nodecnt * sizeof(Node);
    int size2 = cnt * sizeof(Double);
    printf("tree space : %d bit\n", size1);
    printf("double tree space: %d bit\n", size2);
    printf("compress rate :%.2lf%%\n", 100.0 * size2 / size1);
    while(~scanf("%s", str)){
        printf("result : %d\n", search(arr, str));
    }
    free(arr);
    return 0;
}
