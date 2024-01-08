/*************************************************************************
	> File Name: 2main.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Jan 2024 04:58:23 PM CST
 ************************************************************************/

#include<iostream>
#include <stack>
#include "paipk.h"
#include "tree.h"
using namespace std;
#define max 18

//提示牌类型
void usages(int n) {
    if(n >= 1) printf("1 : Dan\n");
    if(n >= 2) printf("2 : Duizi\n");
    if(n >= 3) printf("3 : Shunzi\n");
    if(n >= 4) printf("4 : SanDai\n");
    if(n >= 5) printf("5 : ZhaDan\n");
    if(n >= 6) printf("6 : DKing\n");
    if(n >= 7) printf("7 : PASS\n");
    printf("input : ");
    return ;
}

int a[max + 5] = {0};
int b[max + 5] = {0};

//从文件中读取各自拥有牌的信息
void read(FILE *f, int *arr) {
    int x;
    while(fscanf(f, "%d", &x) != EOF) {
        if(x == 0) break;
        arr[x] += 1;
    }
    return ;
}

void read_data() {
    FILE *f = fopen("input", "r");//打开文件
    read(f, a);//读取本人牌的信息
    read(f, b);//对手牌信息
    fclose(f);
    return ;
}

//输出解决方法
void output(Node *root, int *a, int *b){
    stack<Node *> s;
    s.push(root);
    while(!s.empty()) {
        //双方交替出牌“-->”指向即将出牌方
        printf("%s : ", (s.size() % 2) ? "-->" : "  ");
        Pmes::output_ab(a);
        printf("%s : ", (s.size() % 2) ? "  " : "-->");
        Pmes::output_ab(b);
        
        Node *node = s.top();//当前所出的牌
        int m;
        do {
            printf("%d : back\n", -1);//
            //
            for(int i = 0; i < node->child.size(); i++){
                printf("[%d, %s] : ", i, node->child[i]->win ? " " : "win");
                node->child[i]->p->output() << endl;
            }
            cout << "intput: ";
            cin >> m;//输入本次要出的牌
            if(m == -1 || m < node->child.size()) break;
        } while(1);
        //
        if(m == -1) {
            s.pop();
            node->p->back(s.size() % 2 ? a : b);
        } else {
            node->child[m]->p->take(s.size() % 2 ? a : b);
            s.push(node->child[m]);
        }
    }
    return ;
}

int main() {
    read_data();

    Node *root = new Node();//新建
    //获取博弈树
    gettree(root, a, b);
    output(root, a, b);//输出
    return 0;
}

