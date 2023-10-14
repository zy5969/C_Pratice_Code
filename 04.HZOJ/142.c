/*************************************************************************
	> File Name: 142.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Oct 2023 08:26:21 PM CST
 ************************************************************************/

//质数、回文
#include <stdio.h>
#define max 100000

//回文
int res(int i) {
    int a = 0, b = i;
    while(b) {
        a = a * 10 + b % 10;
        b = b / 10;
    }
    return a == i;
}
/*
int zi(int i) {
    int m = 0;
   // if(i == 10) return 0; 
    if(i > 10000){
        for(int a = 2; a < i; a++) {
            if(i % a) m += 1;
            else m -= 1;
        }
        if(m == (i - 2)) return 1;
        else return 0;
    }
    else return 0;
}
*/
int main() {
    int a, b;
    int  n;
    int arr[max + 5] = {0};
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++) {
       int flag = 0;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
            
        }
       // if(!res(i) ) continue;
        if(!flag && res(i)) {
            n && printf(" ");
            printf("%d", i); 
            n++;
        }
        
       
       // else continue;
    }
    printf("\n");
    return 0;
}





