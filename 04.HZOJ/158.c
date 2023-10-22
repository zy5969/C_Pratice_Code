/*************************************************************************
	> File Name: 158.c
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Oct 2023 09:03:16 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2 * n + 1; i > 0; i--) {
        int m = abs(i - n - 1);
        for(int j = 0; j < n - m; j++){
            printf(" ");
        } 
        printf("%d", m); 
        for(int k = 2 * m - 1; k > 0; k--){
            printf(" ");
        }
        m && printf("%d", m);
        printf("\n");
        
    }

    return 0;
}



