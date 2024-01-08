/*************************************************************************
	> File Name: ./include/tree.h
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Jan 2024 03:38:41 PM CST
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H
#include <vector>
#include <paipk>

//声明节点类
class Node {
public :
    Node();
    Node(Pmes *, int);//初始化节点
    int win;//标记
    Pmes *p;
    vector<Node *> child;
};

void gettree(Node *, int *, int *);

#endif
