/*************************************************************************
	> File Name: 196.c
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Nov 2023 07:14:30 PM CST
 ************************************************************************/

//1.2x+3y = N的解的个数
//f(n) = f(n - 2) + f(n - 3)走过的2个台阶和三个台阶的后面的情况和

#include<stdio.h>

int fun(int N){
    if(N == 2 || N == 3) return 1;
    if(N < 2) return 0;
    return fun(N - 2) + fun(N - 3);
}

int main(){
    int N;
    scanf("%d", &N);
    
    printf("%d\n", fun(N));
    return 0;
}


