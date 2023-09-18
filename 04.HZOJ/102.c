//注水问题 (V/a)*T + (V/b)*T-(V/c)*(T-t) = V
#include<stdio.h>
//小数点问题
int  main(){
    int a,b,c,t;
    double T;
    scanf("%d%d%d%d",&a,&b,&c,&t);
    //计算
    int p = a * b * c - a * b * t, q = a * c + b * c - a * b;
  //  T = p / q + (p % q) / q;
    T = 1.0 * p / q;
    printf("%.2lf\n", T);
    return 0;
}

