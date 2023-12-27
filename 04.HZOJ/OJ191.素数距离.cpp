/*************************************************************************
	> File Name: OJ191.素数距离.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Dec 2023 09:31:30 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#define max 8000000
using namespace std;

int prime[max + 5];//素数标记
int indmax = 0;//最大距离
int indmin = 0;//最小距离

void deal_prime(int a, int b){
    for(int i = a; i <= b; i++){
        if(prime[i]) continue;
        for(int j = i, t = (b - a + 1) / 2; j <= t; j++){
            prime[i * j] = 1;
        }
    }
    return;
}
//最值
vector<int> getval(int l, int r){
    vector<int> v2;
    int x = 0;
    indmin = r - l;
    for(int i = l; i <= r; i++){
        if(prime[i]) continue;
        v2.push_back(i);
    }
    for(int i = 1; i < v2.size(); i++){
        int a = v2[i] - v2[i - 1];
        if(indmax < a) indmax = a;
        if(indmin > a) indmin = a;
    }
    return v2;
}

int main() {
    int l, r;
    cin >> l >> r;
    vector<int> v1;
    vector<int> v2;
    vector<vector<int> > v;//素数对
    deal_prime(l, r);
    v2 = getval(l, r);
    if(v2.size() == 0 || v2.size() == 1) {
        cout << "There are no adjacent primes." << endl;
        return 0;
    }
    for(int i = 1; i < v2.size(); i++){
        if(indmin != indmax && v2[i] - v2[i - 1] == indmin) {
            v1.push_back(1);
            v1.push_back(v2[i - 1]);
            v1.push_back(v2[i]);
            
            v.push_back(v2);
            v1.clear();
        }
        if(v2[i] - v2[i - 1] == indmax) {
            v1.push_back(0);
            v1.push_back(v2[i - 1]);
            v1.push_back(v2[i]);
            
            v.push_back(v2);
            v1.clear();
        }
    }
    for(int i = 0; i < v.size(); i++){
        int p = v[i][0];
        if(p) printf("%d,%d are closest, ", v[i][1], v[i][2]);
    }
    for(int i = 0, x = 0; i < v.size(); i++){
        int p = v[i][0];
        x && cout << ", ";
        if(!p) {
            printf("%d,%d are most distant", v[i][1], v[i][2]);
            x++;
        }
    }
    cout << "." << endl;
    return 0;
}

