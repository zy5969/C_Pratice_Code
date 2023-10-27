/*************************************************************************
	> File Name: e2.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Oct 2023 10:05:00 PM CST
 ************************************************************************/

//阶乘和 = 本身
/*方式1
#include<stdio.h>
//上限枚举，每一位阶乘求和的函数与10的n次方的函数
#define max 362800 
int fac(int n){
    int m = 1;
    for(int i = n; i > 0; i--){
        m *= i;
    }
    return m;
}

int count(int n){
    int x = n, y = 0, sum = 0;
    while(x){
        y = x % 10;
        x /= 10;
        sum += fac(y);
    }
    return sum;
}

int main() {
    int sum = 0;
    //
    for(int i = 10; i <= max; i++){
        int x = count(i);
        if(i == x){ 
            sum += i;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}

//方式二
//数组对应位置存放其相应的阶乘
void count(int *a){
    a[0] = 1;
    for(int i = 1; i <= max; i++){
        a[i] = i * a[i - 1];
    }
    return ;
}

int deal(int *a, int n){
    int x = n, y = 0;
    //求阶乘和
    while(x){
        y += a[x % 10];
        x /= 10;
    }
    if(n == y) return 1;
    return 0;
}

int main() {
    int sum = 0;
    int arr[max] = {0};
    count(arr);//处理数组
    printf("%d\n", arr[10]);
    for(int i = 10; i <= max ;i++){
        if(deal(arr, i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}


//能被1~20整除的最小数
//求最小公倍数 = 乘积除以最大公约数
#include <stdio.h>

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main() {
    int sum = 1;
    for(int i = 1; i <= 20; i++){
        //sum能够被整除时不需要参与计算
        if(sum % i == 0) continue; 
        sum = i / gcd(i, sum) * sum;
    }
    printf("%d\n", sum);
    return 0;
}

*/

//1001*1001螺旋矩阵对角线数和
#include <stdio.h>

int main() {
    int sum = 1;
    for(int i = 3; i <= 1001; i += 2){
        sum += i * i * 4 - 6 * i + 6;
    }
    printf("%d\n", sum);
    return 0;
}




