/*************************************************************************
**有很多约数的三角形数**
三角形数是通过累加自然数所得到的数。例如，第7个三角形数是1+2+3+4+5+6+7=28。前十个三角形数分别是：
1,3,6,10,15,21,28,36,45,55,…
可以看出，28是第一个约数数量超过五的三角形数。
第一个约数数量超过五百的三角形数是多少？ 
************************************************************************/

#include <stdio.h>
#include <math.h>
#define N 10000

int factorcnt(long long n){
    int cnt = 0;
    for(int i = 1, x = sqrt(n); i <= x; i++){
        if(n % i) continue;
        cnt += 1;
        cnt += (i != n / i);
    }
    return cnt;
}
//暴力求解
void brue() {
    int n = 0;
    while(1) {
        n += 1;
        long long val = (1 + n) * n / 2;//当前三角数
        int cnt = factorcnt(val);
        if(cnt <= 500) continue;
        printf("val = %lld  cnt = %d\n", val, cnt);
        break;
    }
    return ;
}

//线性筛取100内素数
int arr[N + 5];
void prime(){
    for(int i = 2; i <= N; i++){
        if(!arr[i]) arr[++arr[0]] = i;
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > N) break;
            arr[arr[j] * i] = 1;
            if(i % arr[j] == 0) break;
        }
    }
    return ;
}

int main() {
    
    
    //暴力解法
    brue();
    return 0;
}

/*
列举出前七个三角形数的所有约数：
1: 1
3: 1,3
6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
*/
