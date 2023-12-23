/*************************************************************************
 第10001个质数是多少？
 ************************************************************************/

#include<iostream>
#define max 1000000
using namespace std;

int arr[max + 5] = {1, 1};
int a[max + 5] = {0};
//素数筛
void prime(){
    for(int i = 2; i <= max; i++){
        if(arr[i]) arr[i] = i;
        for(int j = 2, t = max / i; j <= t; j++){
            arr[i * j] = i;
        }
    }
    return ;
}

//线性筛取arr[10001]
int primes() {
     for(int i = 2; i < max; i++){
        if(!a[i]) a[++a[0]] = i;//从1开始记录素数值
        for(int j = 1; j <= a[0]; j++){
            if(a[j] * i > max) break;//被标记的值不超过范围
            a[a[j] * i] = 1;
            if(i % a[j] == 0) break;//i中最小素因子与arr[j]相等
        }
    }
 //   cout << a[10001] << endl;
    return 1;
}


int main() {
    int n = 0, val = 0;
    prime();
    primes();
    for(int i = 2; i <= max; i++){
        if(arr[i]) continue;
        n++;
        if(n == 10001) {
            val = i;
            break;
        }
    }
    cout << val << endl;
    cout << a[10001] << endl;
    return 0;
}


