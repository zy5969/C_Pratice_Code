/*************************************************************************
斐波那契数列中的每一项都是前两项的和。由1和2开始生成的斐波那契数列的前10项为：
1,2,3,5,8,13,21,34,55,89
考虑该斐波那契数列中不超过四百万的项，求其中为偶数的项之和。
************************************************************************/

#include<iostream>
#define max 4000000

using namespace std;
int arr[max] = {0};//数组求所有项

int main() {
    //求每项，判断，求和，三个变量
    int a = 1, b = 2;
    int sum = 2, c;//int 快于long
    do{
        c = a + b;
        a = b;
        b = c;
        if(c % 2 == 0) sum += c;
    } while(c <= max);
    cout << "三个变量: " << sum << endl;
    //数组获取所有
    arr[1] = 1, arr[2] = 2;
    int x = 2;
    while(arr[x] + arr[x - 1] <= max){
        x += 1;
        arr[x] = arr[x - 2] + arr[x - 1];
    }
    int sum1 = 0;
    for(int i = 1; i <= x; i++){
        //或 arr[i] & 1 == 0
        if(arr[i] % 2 == 0) sum1 += arr[i];
    }
    cout << "数组获取: " << sum1 << endl;
    //滚动数组
    int arr1[3] = {0, 1, 2};
    int y = 2, sum2 = 2;
    while(arr1[y % 3] + arr1[(y - 1) % 3] <= max){
        y += 1;
        arr1[y % 3] = arr1[(y - 1) % 3] + arr1[(y - 2) % 3];
        if(arr1[y % 3] % 2 == 0) sum2 += arr1[y % 3];
    }
    cout << "滚动数组: " << sum2 << endl;
    //两个变量
    int n = 1, m = 2, sum3 = 2;
    while(n + m <= max){
        m = n + m;
        n = m - n;
        if(m % 2 == 0) sum3 += m;
    }
    cout << "两个变量: " << sum3 << endl;
}

