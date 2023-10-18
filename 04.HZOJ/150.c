/*************************************************************************
	> File Name: 150.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 09:21:29 PM CST
 ************************************************************************/

#include <stdio.h>
#define max 200

int main() {
    int n, m;    
    int arr[max + 5][max + 5] = {0};
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);     
        }
    }   
    printf("\n");
    for(int i = 0; i < m; i++) {
        for(int j = n - 1; j >= 0; j--) {
            (n - j - 1) && printf(" ");
            printf("%d", arr[j][i]);
        }
        printf("\n");
    }
 //   output(arr, n, m);
  //  printf("%d %d\n", n, m);
    return 0;
}


