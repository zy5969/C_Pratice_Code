/**************************************************
	> File Name: min-max.cpp
 
**************************************************/

#include<iostream>
#include <vector>
using namespace std;

class Node {
public:
    int n, flag;//剩余,flag = 1
    vector<Node *> next; 
    Node(int n, int flag = 0) : n(n),flag(flag){} //默认必败
    void output() {
        printf("n = %d, flag = %d ", n, flag);
        for(int i = 0; i < this->next.size(); i++){
            printf("%d, ", this->next[i]->n);
        }
        printf("\n");
    }
};

Node *getnewnode(int n){
    Node *p = new Node(n);//当前节点数n
    return p;
}

Node *gettree(int n){
    if(n == 1) {
        return getnewnode(n);
    }
    Node *root = getnewnode(n);//当前节点
    root->next.push_back(gettree(n - 1));//子节点，取1个
    root->next.push_back(gettree(n - (n / 2)));//取一半
    for(int i = 0; i < root->next.size(); i++){
        if(root->next[i]->flag == 0) {
            root->flag = 1;
            break;
        } 
    }
    return root;
}

void output(Node *root){
    if(root == NULL) return ;
    root->output();
    for(int i = 0; i < root->next.size(); i++){
        output(root->next[i]);
    }
    return ;
}


int main() {
    int n;
    cin >> n;
    Node *root = gettree(n);
    if(root->flag) cout << "Win" << endl;
    else cout << "Lose" << endl;
//    output(root);//情况
    return 0;
}

