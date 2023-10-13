/*************************************************************************
	> File Name: 140.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Oct 2023 08:47:39 PM CST
 ************************************************************************/

//输出菱形
#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    char s = 0x41;
    for(int i = 1; i <= n; i++) {
        int m = n - i;
        
        while(m){
            printf(" ");
            m--;
        }
        for(int j = 0; j < 2 * i - 1; j++) {
            
            printf("%c", s);
        }
        s++;
        printf("\n");
        
    }
    s -= 2;
    for(int i = n - 1; i >= 1; i--) {
        int m = n - i;
        while(m){
            printf(" ");
            m--;
        }

          
    //    (m--) && printf(" ");
        for(int j = 2 * i - 1; j > 0; j--) {
         //  if(n == 2)  printf("%c", s - n);
            printf("%c", s);
        }
        s--;
        printf("\n");
        
    }
    return 0;
}


