/*************************************************************************
 在这个方阵中，四个呈一直线（竖直、水平或对角线）相邻的数的乘积
 最大是多少？
 ************************************************************************/

#include<iostream>
#define max 20
using namespace std;

int grid[max + 5][max + 5];
//方向数组，4个方向上的坐标
int dir[4][2] = {
    {-1, 0}, {-1, 1},
    {0, 1}, {1, 1}
};

//求积
int count(int x, int y){
    int val = 0;
    for(int i = 0; i < 4; i++){//取4个数
        int sum = 1;
        for(int k = 0; k < 4; k++){
            int a = x + k * dir[i][0];//0位置对应横坐标,i方向
            int b = y + k * dir[i][1];//1位置对应纵坐标
            if(a < 0 || a >= max) break;
            if(b < 0 || b >= max) break;
            sum *= grid[a][b];//该线上数的乘积
        }
        if(sum > val) val = sum;
    }
    return val;
}

int main() {
    //获取数组
    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            cin >> grid[i][j];
        }
    }
    int val = 0;
    //数组中每位数符号条件的四个方向的最大值
    for(int k = 0; k < max; k++){
        for(int j = 0; j < max; j++){
            int a = count(k, j);
            if(a > val) val = a;
        }
    }
    cout << val << endl;
    return 0;
}

