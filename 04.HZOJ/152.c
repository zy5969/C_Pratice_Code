/*************************************************************************
	> File Name: 152.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Oct 2023 08:25:43 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 4) n = n + 3;
    else if(n == 5) n = 1;
    else if(n == 6) n = 2;
    else if(n == 7) n = 3;
    switch(n) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
        case 7: printf("Sunday\n"); break;
    }

    return 0;
}




