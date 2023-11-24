/*************************************************************************
	> File Name: 204.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 09:30:08 PM CST
 ************************************************************************/

//大量数据不出结果
//对角线上的身高
/*
#include <stdio.h>

typedef struct student {
    int arr[1000];//存储身高
    int h;//数量
}student;

int main() {
    student *s;
    int n, val;
    scanf("%d", &n);
    s->h = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &val);
          //  s->arr[i][j] = val;
            if(i == j) {
                s->arr[s->h] = val;
                s->h++;
            }   
        }
    }
    for(int k = 0; k < s->h; k++){
        
        printf("%d\n", s->arr[k]);
    }

    return 0;
}
*/

#include <stdio.h>

int main() {
    int n, arr[30][30] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            if(a == b) printf("%d\n",arr[a][b]);
        }
    }
    return 0;
}



