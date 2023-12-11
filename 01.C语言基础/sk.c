/*************************************************************************
	> File Name: sk.c 多组数据综合处理
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

//红黄牌子情况数据
typedef struct cases { 
    int time, m;//时间，编号
    char ah, color;//分队，颜色
} Cases;

//得到的红牌数据
typedef struct anser{
    char *s;//队名
    int T, M;//时间，编号
}Anser;

//整体编号排序
void num(Cases *data, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(data[i].m > data[j].m) swap(data[i], data[j]);
        }
    }
    return ;
}

//输出数据排序
void timeorder(Anser *time, int m, char *s1){
    for(int i = 0 ;i < m; i++){
        for(int j = i + 1; j < m; j++){
            if(time[i].T > time[j].T) swap(time[i], time[j]);
            //时间相同，同队编号大在前，异队主队在前
            if(time[i].T == time[j].T ){
                if(!strcmp(time[i].s, time[j].s)){
                    if(time[j].M < time[i].M)  swap(time[i], time[j]);
                }
                else if(strcmp(time[j].s, s1)) swap(time[i], time[j]);
            }
        }
    }
    return ;
}

//黄色牌ah, m, 2y
void yellow(Cases *data, Anser *put, int n, int *a, char *s1, char *s2){
    int sum = *a;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(data[i].color == 'r' || data[j].color == 'r') continue;
            //一个人两张黄牌
            if(data[i].ah == data[j].ah && data[i].m == data[j].m) {
                if(data[i].ah == 'h') put[sum].s = s1;
                else put[sum].s = s2;
                put[sum].T = data[i].time;
                put[sum].M = data[i].m;
                sum++;
                
            }
        }
    }
    *a = sum;
  //  printf("sum: %d\n", sum);
    return ;
}

//处理整个数据组
int dealing(Cases *data, Anser *put, int n, char *s1, char *s2){
    //取红色牌
    int a = 0;//红牌个数
    for(int i = 0; i < n; i++){ 
        if(data[i].color == 'r') {
            if(data[i].ah == 'h') put[a].s = s1;
            else put[a].s = s2;
            put[a].T = data[i].time;
            put[a].M = data[i].m;
            a++;
        }
    }
    yellow(data, put, n, &a, s1, s2);
//    printf("a: %d\n", a);
    return a;
}
//结果输出
void output(Anser *put, int m){
    for(int i = 0; i < m; i++){
        printf("%s %d %d\n", put[i].s, put[i].M, put[i].T);
    } 
    return;
}

int main() {
    int n;
    char s1[20] = {0}, s2[20] = {0};
    Cases data[100] = {0};
    Anser put[100] = {0};
    scanf("%s%s%d", s1, s2, &n);
    for(int i = 0; i < n; i++){
        scanf("%d%s", &data[i].time, &data[i].ah);
        scanf("%d%s", &data[i].m, &data[i].color);
    }
    printf("\n");
   // num(data, n);
 /*   for(int j = 0; j < n; j++){
        printf("%d %c %d %c\n", data[j].time, data[j].ah, data[j].m, data[j].color);
    }*/
    int m = dealing(data, put, n, s1, s2);//统计
    timeorder(put, m, s2);//排序
    if(m == 0) printf("No Red Card\n");
    else output(put, m);
    return 0;
}


