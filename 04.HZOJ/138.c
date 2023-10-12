/*************************************************************************
	> File Name: 138.c
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Oct 2023 08:17:41 PM CST
 ************************************************************************/

//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = n; i > 0; i--) {
        for(int j = 2 * i; j > 0; j--){
            printf("A");
        }
        printf("\n");
       // n--;
    }


    return 0;
}


