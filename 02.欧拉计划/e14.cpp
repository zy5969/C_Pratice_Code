/*************************************************************************
 考虑如下定义在正整数集上的迭代规则：
 （若为偶数）n--->n/2
 （若为奇数）n--->3n+1
从开始，可以迭代生成如下的序列：
13-->40-->20-->10-->5-->16-->8-->4-->2-->1
可以看出这个序列（从13开始到1结束）共有10项。
尽管还未被证明，但普遍认为，从任何数开始最终都能
抵达1并结束（这被称为“考拉兹猜想”）。
在小于一百万的数中，从哪个数开始迭代生成的序列最长？
注： 在迭代过程中允许出现超过一百万的项。
 ************************************************************************/

#include<iostream>
#define max 1000000
using namespace std;
//递归
long long len(long long n){
    if(n == 1) return 1;
    if(n % 2) return len(3 * n + 1) + 1;
    return len(n / 2);
}
//记忆化,记录前一次计算值跟后面值进行
int arr[max + 5];//存放每次的数字
long long length(long long n){
    if(n == 1) return 1;
    if(n <= max && arr[n]) return arr[n];
    //奇数和偶数判断，计算公式不同n在计算过程中可能大于一百万
    int cnt = (n % 2) ? length(3 * n + 1): length(n / 2);
    cnt++; //记录长度
    if(n <= max) arr[n] = cnt;//记忆当前数的当前长度
    return cnt;
}

int main() {
    int n = 0, l = 0, n2 = 0, l2 = 0;
    for(int i = 1; i <= max; i++){
        int d = length(i);
        if(d < l) continue;
        l = d;
        n = i;
    }
    for(int i = 1; i <= max; i++){
        int a = len(i);
        if(a < l2) continue;
        l2 = a;
        n2 = i;
    }
    cout << "记忆化: " << n << " " << l << endl;
    cout << "递归法: " << n2 << " " << l2 << endl;
    return 0;
}

