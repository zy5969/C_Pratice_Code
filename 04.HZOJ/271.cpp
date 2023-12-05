/*************************************************************************
	> File Name: 271.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2023 10:36:39 PM CST
 ************************************************************************/

//滑动数组求每组的最大最小值
#include<cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 300000

int arr[max_n + 5] = {0};
void quick(int *s, int l, int r){
    if(l > r) return ;
    int x = l, y = r, z = s[l];
    while(x < y){
        while(x < y && s[y] >= z) y--;
        if(x < y) s[x++] = s[y];
        while(x < y && s[x] <= z) x++;
        if(x < y) s[y--] = s[x];
    }
    s[x] = z;
    quick(s, l, x - 1);
    quick(s, x + 1, r);
    return ;
}
//取值并返回
int p = 0;
int getval(int *num,int x, int y, int flag){
    int n = num[x], m = num[x];

    for(int i = x + 1; i <= y; i++){
        if(num[i] > n) n = num[i];
        if(num[i] < m) m = num[i];
    }
    if(flag == 1) return n;
    if(flag == 2) return m;
}

int qsort(int *num, int x, int y, int flag){
    int num1[max_n + 5] = {0};
    for(int i = x; i <= y; i++){
        num1[i] = num[i];
    }
    sort(num1 + x , num1 + y + 1);
    if(flag == 0) return num1[y];
    return num1[x];
}

void output(int *a, int n){
    for(int i = 0; i < n; i++){
        i && printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return ;
}

int ary[max_n + 5] = {0};
void count(int *a, int *b, int n, int k){
    int p = 0;
    for(int i = 1, j = 0; i <= n - 1; i++){
        ary[i] = arr[i];
        
        if(i >= k - 1){
        //    a[p] = getval(ary, i - k + 1, i, 1);
        //    b[p] = getval(ary, i - k + 1, i, 2);
            a[p] = qsort(ary, i - k + 1, i, 0);
            b[p] = qsort(ary, i - k + 1, i, 1);
            p++;
        }
    }
    return ;
}



int main() {
    int N, k;
    int min[max_n + 5] = {0};
    int max[max_n + 5] = {0};
    scanf("%d%d", &N, &k);
    for(int i = 0; i < N; i++){
       scanf("%d", &arr[i]);
    }
    //处理数组存放极大值和极小值
    count(max, min, N, k);
    output(min, N - k + 1);
    output(max, N - k + 1);
    return 0;
}




