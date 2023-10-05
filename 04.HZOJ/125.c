/*************************************************************************
	> File Name: 125.c
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 11:16:46 PM CST
 ************************************************************************/

//输入24小时   输出12小时
#include <stdio.h>
//时间判断

int main () {
    int h, m, s, t;
//    double t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    int s1 = (s + t % 60) % 60;//结束小时
    int m1 = (m + t % 3600 / 60) % 60 + (s + t % 60) / 60;
    int h1 = h + t / 3600 + (m + t % 3600 / 60) / 60;//结束小时
   // printf("%d %d %d\n", h1, m1, s1);
   
    if(h1 < 12 && h1 > 0) printf("%d:%d:%dam\n", h1, m1, s1);
    if(h1 > 12 && h1 < 24) printf("%d:%d:%dpm\n", h1 - 12, m1, s1);
    if(h1 > 24 && h1 < 36) printf("%d:%d:%dam\n",h1 - 24, m1, s1);
    if(h1 > 36) printf("%d:%d:%dpm\n", h1 - 36, m1, s1);
    if(h1 == 24 || h1 == 48) printf("%d:%d:%dam\n", 12, m1, s1);
    if(h1 == 12 || h1 == 36) printf("%d:%d:%dpm\n", 12, m1, s1);

   double t1 = 1.0 * t / 86400 * 100; 
    printf("%.2lf", t1);
    printf("%c", 0x25);
    printf("\n");
    return 0;
}



