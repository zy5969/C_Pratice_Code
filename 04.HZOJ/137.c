/*************************************************************************
	> File Name: 137.c
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Oct 2023 07:50:13 PM CST
 ************************************************************************/

//字母三角形
#include <stdio.h>

int main() {

    int n , p = 0; 
    char m = 0x41;
    scanf("%d", &n);
    
    for(int i = 0; i <= n + p ; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", m + j);
        } 
        m = m + n;
        printf("\n");
        n--;
        p++;
    }

    return 0;
}



