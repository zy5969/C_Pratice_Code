/*************************************************************************
从如下数字三角形的顶端出发到达底部，求所能得到的最大路径和。
 ************************************************************************/
//矩阵，坐标
#include <stdio.h>
#include <stdlib.h>
#define max 20
#define maxval(a, b) ({\
    __typeof(a) _c = a;\
    __typeof(b) _d = b;\
    ((_c) > (_d)) ? (_c) : (_d);\
})

int arr[max + 5][max + 5] = {0};
int keep[max + 5][max + 5] = {0};
//记忆化
int sing(int x, int y){
    if(keep[x][y]) printf("%d ", keep[x][y]);
    if(x + 1 >= 15) return arr[x][y];
    if(keep[x][y]) return keep[x][y];
    int val1 = sing(x + 1, y);
    int val2 = sing(x + 1, y + 1);
    if(val1 > val2) return keep[x][y] = val1 + arr[x][y];
    return keep[x][y] = val2 + arr[x][y];//记忆
}

//递归
int count(int x, int y){
    if(x + 1 >= 15) return arr[x][y];
    int val1 = count(x + 1,y);//左边的值
    int val2 = count(x + 1, y + 1);//右边的值
    if(val1 > val2) return val1 += arr[x][y];
    return val2 += arr[x][y];
}

int main() {
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < i + 1; j++){
            int val;
            scanf("%d", &val);
            arr[i][j] = val;
        }
    }
    int val1 = count(0, 0);//顶端开始
    int val2 = sing(0, 0);//顶端开始
    //尾递归,倒数第二行开始加求最后两行的和最大值向上递加
    for(int i = 13; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            //与左右两边的最大值求和
            arr[i][j] += maxval(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }
    printf("\n");
    printf("尾递归 : %d\n", arr[0][0]);
    printf("记忆化 : %d\n", val2);
    printf("递  归 : %d\n", val1);
    return 0;
}
/*
   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 
0                75
1               95 64
2              17 47 82
3             18 35 87 10
4            20 04 82 47 65
5           19 01 23 75 03 34
6          88 02 77 73 07 63 67
7         99 65 04 28 06 16 70 92
8        41 41 26 56 83 40 80 70 33
9       41 48 72 33 47 32 37 16 94 29
10     53 71 44 65 25 43 91 52 97 51 14
11    70 11 33 28 77 73 17 78 39 68 17 57
12   91 71 52 38 17 14 91 43 58 50 27 29 48
13  63 66 04 68 89 53 67 30 73 16 69 87 40 31
14 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
*/


