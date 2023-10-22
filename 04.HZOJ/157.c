/*************************************************************************
	> File Name: 157.c
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Oct 2023 09:02:28 PM CST
 ************************************************************************/


#include<stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int m = 0x41;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n - 1; i++) {
        for(int k = 0; k < n - abs(n - i - 1) - 1; k++) {
            printf(" ");
        }
        for(int j = abs(n - i - 1) * 2 + 1; j > 0; j--) {
            printf("%c", m);
            if(j <= abs(n - i - 1) + 1) m--;
            else m++;
        }
        if(i == n - 1) m -= 2;
        if(i < n) m += 2; 
       
        printf("\n");
    }
    
    return 0;
}






