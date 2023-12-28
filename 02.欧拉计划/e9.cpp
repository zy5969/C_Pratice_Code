/*********************************************
特殊毕达哥拉斯三元组
毕达哥拉斯三元组由三个自然数a<b<c组成，并满足
a2+b2=c2
例如，32+42=9+16=25=52。
有且只有一个毕达哥拉斯三元组满足 a+b+c=1000。求这个三元组的乘积abc。
*************************************************/

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

