/*************************************************************************
	> File Name: 134.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Oct 2023 09:24:57 PM CST
 ************************************************************************/

#include<stdio.h>

int main () {
    int a, b, i;
    scanf("%d%d", &a, &b);
    int j = 0;
    for(i = a; i <= b; i++) {
       
        if(i % 11 == 0) {
            j && printf(" ");

            printf("%d", i);
            j++;
          //  i && printf(" ");
        }
    } 
    printf("\n");
    return 0;
}

