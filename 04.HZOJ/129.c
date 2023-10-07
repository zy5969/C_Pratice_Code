/*************************************************************************
	> File Name: 129.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 09:37:07 PM CST
 ************************************************************************/

//输出最小数
#include<stdio.h>

int main() {
    int n, m, a;
    scanf("%d\n", &n);
   int tab[1005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
       // int tab[n] = {0};
   //     int tab[i] = m;
    }
    for (int j = 0; j < n; j++) {
        if(tab[j] > tab[j + 1]) a = tab[j + 1];
        else a = tab[j];
    }
    printf("%d\n", a);
    return 0;
}


//最后不空格

//if(i != 0) printf(" ");

//i && printf(" ");









