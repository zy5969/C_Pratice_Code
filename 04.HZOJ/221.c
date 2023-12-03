/*************************************************************************
	> File Name: 221.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 09:42:15 PM CST
 ************************************************************************/

//气球，排序
#include <stdio.h>
#define MAX_N 100000
#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}


typedef struct stu {
    int id;
    int height;
}stu;

void quick(stu *a, int l, int r){
    if(r < l) return ;
    int x = l, y = r, t = a[l].height, q = a[l].id;
    while(x < y) {
        while(x < y && a[y].height >= t) y--;
        if(x < y) {
            a[x].height = a[y].height;
            a[x].id = a[y].id;
            x++;
        }
        while(x < y && a[x].height <= t) x++;
        if(x < y) {
            a[y].height = a[x].height;
            a[y].id = a[x].id;
            y--;
        }
    }
    a[x].height = t;
    a[x].id = q;
    quick(a, l, x - 1);
    quick(a, x + 1, r);
    return ;
}

void quickh(int *b, int l, int r){
    if(r < l) return ;
    int x = l, y = r, p = b[l];
    while(x < y){
        while(x < y && b[y] >= p) y--;
        if(x < y)  b[x++] = b[y];
        while(x < y && b[x] <= p) x++;
        if(x < y) b[y--] = b[x];
    }
    b[x] = p;
    quickh(b, l, x - 1);
    quickh(b, x + 1, r);
    return ;
}

void insert(stu *a, int n){
    for(int i = 2; i <= n; i++){
        for(int j = i; j > 1; j--){
            if(a[j].height < a[j - 1].height) {
                swap(a[j].height, a[j - 1].height);
                swap(a[j].id, a[j - 1].id);
            }
        }
    }
    return ;
}

void select(int *b, int n){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(b[i] > b[j]) swap(b[i], b[j]);
        }
    }
    return ;
}

void slove(stu *arr, int n, int *q, int m ){
    int result[MAX_N + 5]={0};
    int i = 1;
    for (int j = 1; j <= n; j++){
        for( ; i <= m; i++ ){
            if (arr[j].height < q[i]) break;
            result[arr[j].id] += 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d\n", result[i]);
    }
    return ;
}

int main() {
    int n,m,q[MAX_N + 5] = {0};
    stu arr[MAX_N + 5] = {0};
    scanf("%d%d",&n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i].height);//跳起的高度
        arr[i].id = i;//下标
    }
    for (int j = 1;j <= m; j++){
        scanf("%d", &q[j]);//气球高度
    }
 //   insert(arr, n);
    quick(arr, 1, n);
    quickh(q, 1, m);
 //   select(q, m);
//    sort(arr, arr + n, cmp);
//    sort(q, q + m);
    slove(arr, n, q, m);
    return 0;
}







