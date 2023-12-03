/*************************************************************************
	> File Name: 221.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 09:43:13 PM CST
 ************************************************************************/

//气球，排序
//结构体
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

typedef struct stu {
    int id;
    int height;
}stu;

int cmp(stu a, stu b) {
    return a.height < b.height;
}

void slove(stu *arr, int n, int *q, int m ){
    int result[MAX_N + 5]={0};
    int i=0;
    for (int j = 0; j < n; j++){
        for( ; i < m; i++ ){
            if (arr[j].height < q[i]) break;
            result[arr[j].id] += 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d\n", result[i]);
    }
    return ;
}

int main() {
    int n,m,q[MAX_N + 5];
    stu arr[MAX_N + 5] = {0};
    scanf("%d%d",&n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i].height);
        arr[i].id = i + 1;
    }
    for (int i = 0;i < m; i++){
        scanf("%d", q + i);
    }
    sort(arr, arr + n, cmp);//自动排序
    sort(q, q + m);//气球排序
    slove(arr, n, q, m);
    return 0;
}




