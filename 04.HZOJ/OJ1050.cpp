/*************************************************************************
	> File Name: OJ1050.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Dec 2023 03:35:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max 10000

int prime[max + 5] = {0};
//线性筛
void dealnum(){
    for(int i = 2; i < max; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    int n, m = 0;
    dealnum();
    scanf("%d", &n);
    for(int i = 1; i < max; i++){
        if(prime[i + 1] - prime[i] == 2) m++; 
        if(m == n) {
            cout << prime[i] << " " << prime[i + 1];
            break;
        }
    }
    cout << endl;
    return 0;
}

