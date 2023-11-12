/*************************************************************************
	> File Name: 188.c
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Nov 2023 08:43:12 PM CST
 ************************************************************************/

//素数筛选
#include<stdio.h>
#define max_n 1000000

int arr[max_n + 5] = {0};

void prim( int n){
    for(int a = 0; a <= n; a++){
       // if(!arr[a]) continue ;
        for(int i = 2; i * i <= arr[a]; i++){
            if(arr[a] % i == 0) {
                arr[a] = 1;
                break;
            }
        }
    }
}

int main() {
    int n, m;
  //  int arr[max_n + 5] = {0};
    scanf("%d%d", &n, &m);
    for(int i = m; i <= n; i++){
        arr[i] = i;
    }
    prim(n);
    for(int k = m; k <= n; k++){
        if(arr[k] == 0 || arr[k] == 1) continue;
        printf("%d\n", arr[k]);
    }
  /*  for(int i = m; i <= n; i++){
        int flag = 0;
        for(int a = 2; a * a <= i; a++){
            if(i % a == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("%d\n", i);
    }
    */
    
    return 0;
}


