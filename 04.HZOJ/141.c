/*************************************************************************
	> File Name: 141.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Oct 2023 08:48:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
/*
int main() {
    int n;
    int m  = 0x41;
    scanf("%d", &n);
    for(int i = n + 1; i > 0; i--) {
        int t = 0;
        for(t; t < n - i + 1; t++){
            printf(" ");
        }
        for(int j = 2 * i - 1; j > 0; j--) {
            printf("%c", m);
            if(j > ((2 * i - 1) / 2 +1)) m += 1;
            else m -= 1;
        }
        m += 2;
        printf("\n");
    }
    m -= 2;
    for(int i = 1; i < n + 1; i++) {
       
        for(int x = 0; x < n - i; x++){
            printf(" ");
        }
        for(int j = 2 * i + 1; j > 0; j--) {
            printf("%c", m);
            if(j <= ((2 * i + 1) / 2 + 1)) m -= 1;
            else m += 1;
            
        }
        
        printf("\n");
        
    }

    return 0;
}
*/


int main() {
    int n;
    int m = 0x41;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n + 1; i++) {
        for(int k = 0; k < n - abs(n - i); k++) {
            printf(" ");
        }
        for(int j = abs(n - i) * 2 + 1; j > 0; j--) {
            printf("%c", m);
            if(j-1 < abs(n - i)) m--;
            else m++;
        }
        if(i == n - 1) m -= 2;
        if(i < n) m += 2; 
        printf("\n");
    }
    
    return 0;
}



