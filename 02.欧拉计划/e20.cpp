/***********************************************************
阶乘数字和
n! 的意思是 n×(n−1)×…×3×2×1。
例如，10!=10×9×…×3×2×1=3628800，所以10!的各位数字和
是3+6+2+8+8+0+0=27。
求100!的各位数字和。
***********************************************************/

#include <stdio.h>
#define max 200

int a[max + 5];

int main() {
    int val = 0;
    a[0] = a[1] = 1;
    for(int i = 1; i <= 100; i++){
        //每一次乘积的结果存入数组a,由1开始
        for(int j = 1; j <= a[0]; j++) a[j] *= i;
        //处理进位
        for(int k = 1; k <= a[0]; k++){
            if(a[k] < 10) continue;
            a[k + 1] += a[k] / 10;
            a[k] %= 10;
            a[0] += (k == a[0]);
        }
    }
    for(int i = 1; i <= a[0]; i++){
        val += a[i];
    }
    printf("%d\n", val);
    return 0;
}

