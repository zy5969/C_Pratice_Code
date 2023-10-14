/*************************************************************************
	> File Name: 143.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Oct 2023 08:27:09 PM CST
 ************************************************************************/

#include <math.h>
#include <stdio.h>

int zishu(int c) {
    int x = 0;
    if(c == 2) return 1;
    if(c > 2) {
        for(int i = 2; i < c; i++) {
            if(c % i) x += 1;
            else x -= 1;
        }
        if(x == (c - 2)) return 1;
        else return 0;
    }
}

int sqr(int d) {
    int m = 0;
    if(d == 0) return 0; 
    if(d > 0) {
        for(int i = 1; i < d; i++) {
            if(i * i == d) m += 1;
            else continue ;
        }
        if(m == 1) return 1;
        else return 0;
    }
}

int main() {
    int a, b, c, d;
    scanf("%d%d", &a, &b);
    int n = 0, m , x;
    for(int i = a; i <= b; i++) {
        c = i / 100;
        d = i % 100;
   /*     for(int j = 1; i < d; i++) {
            if(j * j == d) m = 1;
            else m = 0;
        }
     */  
   // printf("%d %d", sqr(d), d);
        if(zishu(c) && sqr(d) && !(i % 6)) {
            n && printf(" ");
            printf("%d", i);
            n++;
        }
      //  printf("%d ", zishu(c));
       
        //printf("%d ", i % 6);
    }
    printf("\n");
    printf("%d\n", n);
    return 0;
}



