/************************************************************************* 克里斯蒂安·哥德巴赫曾经猜想，每个奇合数都可以写成一个素数
和一个平方的两倍之和。
最终这个猜想被推翻了。
不能写成一个素数和一个平方的两倍之和的最小奇合数是多少？
 ************************************************************************/

#include<iostream>
#include<cmath>
#define max 1000000
using namespace std;

//处理数组
int a[max + 5] = {0};//记录素数
int arr[max + 5] = {1, 1};//标记
void prime(){
    for(int i = 2; i < max; i++){
        if(!arr[i]) a[++a[0]] = i;
        for(int j = 1; j <= a[0]; j++){
            if(a[j] * i > max)break;
            arr[a[j] * i] = 1;
            if(i % a[j] == 0) break;
        }
    }
    return ;
}
//判断是否存在2val*val
int search(int val){
    int n = (int)sqrt(val / 2);
    return n * n * 2 == val;
}
//二分查找
int binsearch(int l, int r, int val){
    int n = l, m = r, mid;
    while(n <= m){
        mid = (n + m) / 2;
        if(a[mid] < val) r = mid + 1;
        else if(a[mid] == val) return 1;
        else l = mid - 1;
    }
    return 0;
}

int isval(int n){
    for(int i = 1; i <= a[0] && a[i] < n; i++){
        int val = n - a[i];
        if(search(val)) return 1;
    }
    return 0;
}

int main() {
    prime();
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    int val;
    for(int i = 9; i <= max; i += 2){
        if(!arr[i]) continue;
        if(isval(i)) continue;
        val = i;
        break;
    }
    cout << val << endl;
    return 0;
}


