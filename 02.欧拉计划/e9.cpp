/*************************************************************************
	> File Name: e9.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Dec 2023 08:51:24 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int gcd(int a, int b){
    return((b == 0) ? a : gcd(b, a % b));
}

int main() {
    int val = 0;
    for(int n = 1; n <= 20; n++){
        for(int m = n + 1; m <= 20; m++){
            if(gcd(n, m) != 1) continue;//n, m互素
            int a = 2 * n * m;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if( 1000 % (a + b + c) != 0) continue;
            int x = 1000 / (a + b + c);//在该范围内的倍数
            val = (a * b * c) * (int)pow(x, 3);
            printf("x = %d\n", x);
            printf("a = %d  b = %d  c = %d\n", a, b, c);
            break;
        }
    }
    printf("%d\n", val);
    return 0;
}

