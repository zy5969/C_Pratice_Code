/*****************************************************
五边形数由公式Pn=n(3n−1)/2给出。前十个五边形数是：
1,5,12,22,35,51,70,92,117,145,…
可以看出P4+P7=22+70=92=P8。然而，它们的差70−22=48并不是五边形数。
在所有和差均为五边形数的五边形数对Pj和Pk中，找出使D=|Pk−Pj|最小
的一对；此时D的值是多少？
 *******************************************************/
//二分查找

#include<stdio.h>
#include <inttypes.h>
#define max 10000000

typedef long long lint;

//五边形数
lint agonal(int n){
    return (n * (3 * n - 1) / 2);
}

lint is_agonal(lint m, lint n){
    lint a = 1, b = n, mid;
    while(a <= b){
        mid = (a + b) / 2;
        //直接查找范围内是否有符合值
        if(agonal(mid) == m) return 1;
        if(agonal(mid) < m) a = mid + 1;
        else b = mid - 1;
    }
    return 0;
}

int main() {
    lint sum = INT32_MAX, i = 1, j = 1;
    //k 位置与k-1位置大于D时，有最小值
    while(agonal(j + 1) - agonal(j) < sum) {
        j += 1;
        i = j - 1;
        //Pk - Pj >= D时可结束
        for( ; i >= 1 && agonal(j) - agonal(i) < sum; i--) {
          //  lint a = agonal(j), b = agonal(i);
            if(!is_agonal(agonal(j) + agonal(i), 2 * j)) continue;
            if(!is_agonal(agonal(j) - agonal(i), 2 * i)) continue;
            else {
                printf("%lld---->%lld\n", agonal(j), agonal(i));
                sum = agonal(j) - agonal(i);
                printf("sum = %lld\n", sum);
                return 1;
            }
        }
    }
    return 0;
}

