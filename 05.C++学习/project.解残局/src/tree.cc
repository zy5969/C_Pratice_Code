/*************************************************************************
	> File Name: tree.cc
	> Author: 
	> Mail: 博弈树
	> Created Time: Sun 07 Jan 2024 09:19:36 PM CST
 ************************************************************************/

#include "paipk.h"
#include "tree.h"
using namespace std;
#define max 18
Node::Node() : p(new PASS()), win(0) {} //win最开始标记为必败
Node::Node(Pmes *p, int win = 0) : p(p), win(win) {}

//判断牌是否存在
static bool isempty(int *arr) {
    for(int i = 3; i < max; i++){
        if(arr[i]) return false;
    }
    return true;
}

//获取博弈树,b，对手的牌
void gettree(Node *root, int *a, int *b) {
    if(isempty(b)) {
        root->win = 0;//对手牌为空，失败
        return ;
    }

    vector<Pmes *> v = Pmes::getpais(a, root->p);
    for(int i = 0; i < v.size(); i++){
        Node *q = new Node(v[i]);
        v[i]->take(a);//去除已出的牌
        gettree(q, b, a);
        v[i]->back(a);//放入未出的牌
        root->child.push_back(q);//子节点，存入出牌后的情况
        if(q->win == 0) {
            root->win = 1;
            break;
        }
    }
    return ;
}

