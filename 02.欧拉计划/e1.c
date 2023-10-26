/*************************************************************************
	> File Name: e1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2023 09:03:08 AM CST
 ************************************************************************/

#include<stdio.h>
#define max 1000
#define max_1 4000000

//不超过4000000的项中为偶数项的和
int count1(){
    long long a = 1, b = 1, c = 0, sum = 0;
    for(int i = 0; i <= 44 || c <= max_1; i++){
        c = a + b;
        a = b;
        b = c;
      //  printf("%lld ", c);
        if(c % 2 == 0) sum += c;
    }
    printf("%lld\n", sum);
    return 0;
}

int arr[50] = {0};
void count2() {
    arr[0] = 1;
    arr[1] = 1;
    long long sum = 0;
    for(int i = 2; i <= 44 && arr[i] <= max_1; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for(int j = 0; arr[j]; j++){
        if(arr[j] % 2 == 0) sum += arr[j];
    }
    printf("%lld\n", sum);
}

int count3(){
    int arr[3] = {1, 1, 0};
    long long sum = 0;
    for(int i = 2; i <= 44; i++){
        arr[i % 3] = arr[(i - 1) % 3] + arr[(i - 2) % 3];
        if(arr[i % 3] % 2 == 0) sum += arr[i % 3];
        
    }
    printf("%lld\n", sum);
    return 0;
}

//1000内3或5的倍数求和
int and() {
    int sum = 0, n = 0, m = 0, s = 0;
    for(int i = 1; i < max; i++){
        if(i % 3 == 0) n += i;
        if(i % 5 == 0) m += i;
        if(i % 15 == 0) s += i;
    }
    sum = m + n - s;
    printf("%d\n", sum);
    return 0;
}

int main() {
    and();
    count1();
    count2();
    count3();
    return 0;
}



