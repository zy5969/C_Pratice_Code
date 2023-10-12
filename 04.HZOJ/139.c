/*************************************************************************
	> File Name: 139.c
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Oct 2023 08:19:02 PM CST
 ************************************************************************/

//输出菱形
#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
 //   int m = n;
    for(int i = 1; i <= n; i++) {
        int m = n - i;
        while(m){
            printf(" ");
            m--;
        }
        for(int j = 0; j < 2 * i; j++) {
            
            printf("%c", 0x41);
        }
        printf("\n");
        
    }
    for(int i = n; i >= 1; i--) {
        int m = n - i + 1;
        
      /*  while(m){
            printf(" ");
            m--;
        }*/
        (m--) && printf(" ");
        for(int j = 2 * i - 2; j > 0; j--) {
            
            printf("%c", 0x41);
        }
        printf("\n");
        
    }
    return 0;
}


