/*************************************************************************
	> File Name: OJ379.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 02:12:31 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N, X;
    stack<int> s;
    vector<int> v;
    vector<int> v2;
    cin >> N;
    int a = 0;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        switch(x){
            case 0:{
                cin >> X;
                s.push(X);
                v.push_back(X);
                if(a < X) a = X;
            } break;
            case 1: {
                if(s.empty()) break;
                s.pop(); 
                v.pop_back();
                //出库后重新查询最大值
                for(int i = 0; i < v.size(); i++){
                    a = 0;
                    if(v[i] > a) a = v[i];
                }
            }break;
            case 2: {
                if(s.empty()) {
                    v2.push_back(0);
                    break;
                }
                //查询数量最多的
                v2.push_back(a);
            } break;
        }
    }
    
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << endl;
    }
    return 0;
}
