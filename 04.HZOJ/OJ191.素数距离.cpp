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
int indmin = 1;//最小距离

void deal_prime(int a, int b){
    for(int i = 2; i <= b; i++){
        if(prime[i]) continue;
        for(int j = i, t = (max) / i ; j <= t; j++){
            prime[i * j] = 1;
        }
    }
/*    for(int i = a; i <= b; i++){
        printf("%d ", prime[i]);
    }
    cout << endl;*/
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
    if(v2.empty()) return v2;
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
    vector<vector<int> > vec;//素数对
    deal_prime(l, r);
    v2 = getval(l, r);
    if(v2.size() == 0 || v2.size() == 1) {
        cout << "There are no adjacent primes." << endl;
        return 0;
    }
//    cout << "max = " << indmax << " min = " << indmin << endl;
    for(int i = 1; i < v2.size(); i++){
        if(v2[i] - v2[i - 1] == indmin) {
            v1.push_back(v2[i - 1]);
            v1.push_back(v2[i]);
            
            v.push_back(v1);
            v1.clear();
        }
        if(v2[i] - v2[i - 1] == indmax) {
            v1.push_back(v2[i - 1]);
            v1.push_back(v2[i]);
            
            vec.push_back(v1);
            v1.clear();
        }
    }
    for(int i = 0; i < v.size(); i++){
        printf("%d,%d are closest, ", v[i][0], v[i][1]);
        break;
    }
    for(int i = 0; i < vec.size(); i++){
        printf("%d,%d are most distant.", vec[i][0], vec[i][1]);
        break;
    }
    cout << endl;
    return 0;
}

