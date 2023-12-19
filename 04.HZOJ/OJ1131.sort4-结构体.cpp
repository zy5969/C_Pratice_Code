/*************************************************************************
	> File Name: OJ1131.sort4-结构体.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 05:22:26 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node {
    int x, y;
};

bool cmp(Node a, Node b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n;
    vector<Node> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        Node node;
        cin >> node.x >> node.y;
        v.push_back(node);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << v[i].x << " " << v[i].y << endl;
    }
    return 0;
}

