/***********************************************
1000位斐波那契数
斐波那契数列是按如下递归定义的数列：
Fn=Fn−1+Fn−2，且F1=1，F2=1。
因此斐波那契数列的前12项分别是：
F1=1 F2=1 F3=2 F4=3 F5=5 F6=8 F7=13
F8=21 F9=34 F10=55 F11=89 F12=144
在斐波那契数列中，第一个包含三位数字的是第12项F12。
在斐波那契数列中，第一个包含1000位数字的是第几项？
 **********************************************/

#include <stdio.h>
#define max 1000 //

int num[max + 5];

int main() {
    num[0] = 1, num[1] = 1, num[2] = 1;
    for(int i = 3; i <= 100; i++){
        for(int j = 2; j <= num[0]; j++) num[j] += num[i - 1];
     //   num[i] = num[i - 1] + num[i - 2];
        for(int k = 1; k <= num[0]; k++){
            if(num[i] < 10) continue;
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
            num[0] += (i == num[0]);
        }
    }
    printf("%d\n", num[0]);
    return 0;
}

