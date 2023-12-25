/**************************************************
 首次出现连续四个数均有四个不同的质因数时，
 其中的第一个数是多少？
 *************************************************/

#include<iostream>
#define max 1000000
using namespace std;

int pri_num[max + 5] = {0};//质因数个数
int prime[max + 5];
//线性筛
void deal_pri(){
    for(int i = 2; i < max; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}
//素因子个数统计
void count_pri(){
    for(int i = 2; i < max; i++){
        if(pri_num[i]) continue;
        for(int j = i; j < max; j += i){ //倍数增长
            pri_num[j] += 1;//多次i循环可能会出现相等的j值
            //j出现的个数即质因子个数
        }
    }
    return ;
}

int main() {
    count_pri();
    for(int i = 1; i < max; i++){
        int flag = 1;
        for(int j = 0; j < 4; j++){ //连续4个数
            if(pri_num[i + j] != 4) {
                flag = 0;//查找时出现不是四个质因子跳过重新判断
                break;
            }
          //  flag = (pri_num[i + j] == 4);
        }
        if(flag) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

