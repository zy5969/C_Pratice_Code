/*************************************************************************
	> File Name: e3.c
	> Author: 
	> Mail: 
	> Created Time: Sat 28 Oct 2023 08:46:41 PM CST
 ************************************************************************/

#include <stdio.h>

//回文数判断
int reverse(int n) {
    int num = 0, m = n;
    while(m) {
        num = num * 10 + m % 10;
        m = m / 10;
    }
    return num == n;

}
/*
int main() {
    int n = 0;
    for(int i = 100; i < 1000; i++){
        for(int j = 100; j < 1000; j++) {
            if(reverse(i * j) && i * j > n) n = i * j; 
        }
    }
    printf("%d\n", n);
    return 0;
}
int main() {
    int n = 0;
    for(int i = 100; i < 1000; i++){
        for(int j = i; j < 1000; j++) {
            if(reverse(i * j) && i * j > n) n = i * j; 
        }
    }
    printf("%d\n", n);
    return 0;
}

*/

int main() {
    int n = 0;
    for(int i = 100; i < 1000; i++){
        for(int j = (n / i >= 100 ? n / i + 1 : i); j < 1000; j++) {
            if(reverse(i * j)) n = i * j; 
        }
    }
    printf("%d\n", n);
    return 0;
}

