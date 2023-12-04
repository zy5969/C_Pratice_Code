/*************************************************************************
	> File Name: 270.c
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Dec 2023 09:47:41 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 300000

//单调队列
int queue(int *arr, int n, int m){
    int a[max_n + 5] = {0};//存放和
    int s = 0, h = 0, t = 0;
    for(int i = 1; i <= n; i++){
        s += arr[i + t];
        printf("%d ", s);

      //  if(t - h && a[h] <= s) h--;
      //  a[h++] = s;
      //  if(i == n && t < m) t++;
    }
}

int main() {
    int n , m;
    int arr[max_n + 5] = {0};
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    long sum = 0;
    for(int i = 1; i <= m; i++){
        long cnt = 0;
        for(int j = 1; j <= n; j++){
            cnt += arr[j];
            if(j > i) cnt -= arr[j - i];
            if(cnt > sum) sum = cnt;
        }
        printf("\n");
    }
    printf("%ld\n", sum);
    return 0;
}



