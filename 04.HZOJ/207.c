/*************************************************************************
	> File Name: 207.c
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Nov 2023 09:49:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct student {
    char name[10];
    int sum;
}student;

void swapname(student *s, int n, int m){
    char str[10] = {0};
    strcpy(str, s[n].name);
    strcpy(s[n].name, s[m].name);
    strcpy(s[m].name, str);
    return ;
}

void quickl(student *a, int l, int r){
    if(l > r) return ;
    int x = l, y = r, c = a[l].sum;
    char p[15] = {0};
    strcpy(p, a[l].name);
    while(x < y) {
        while(x < y && a[y].sum >= c) y--;
        if(x < y){
            a[x].sum = a[y].sum;
            strcpy(a[x].name, a[y].name);
            x++;
        }
        while(x < y && a[x].sum <= c) x++;
        if(x < y) {
            a[y].sum = a[x].sum;
            strcpy(a[y].name, a[x].name);
            y--;
        }
    }
    a[x].sum = c;
    strcpy(a[x].name, p);
    quickl(a, l, x - 1);
    quickl(a, x + 1, r);
    return ;
}

void insert(student *s, int n){
    for(int i = 2; i <= n; i++){
        for(int j = i; j > 1; j--){
            if(s[j].sum > s[j - 1].sum) {
                swap(s[j].sum, s[j - 1].sum);
                swapname(s, j, j - 1);
            }
        }
    }
    return ;
}

void quick(int *a, int l, int r){
    if(l > r) return ;
    int x = l, y = r, c = a[l];
    while(x < y) {
        while(x < y && a[y] >= c) y--;
        if(x < y) a[x++] = a[y];
        while(x < y && a[x] <= c) x++;
        if(x < y) a[y--] = a[x];
    }
    a[x] = c;
    quick(a, l, x - 1);
    quick(a, x + 1, r);
    return ;
}

void select(int *a, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]) swap(a[i], a[j]);
        }
    }
    return ;
}

int main() {
    int n, a = 0;
    int arr[125] = {0};
    student stu[35] = {0};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int d;
        scanf("%s", stu[i].name);
        for(int j = 0; j < 4; j++){
            scanf("%d", &d);
            stu[i].sum += d;
            arr[a] = d;
            a++;
        }
    }
    for(int k = 1; k <= n; k++){
        printf("%d\n", stu[k].sum);
    }
    quickl(stu, 1, n);
  //  insert(stu, n);
    quick(arr, 0, a - 1);
  //  select(arr, a);
    printf("%s\n", stu[n].name);
    printf("%d %d\n", arr[a - 1], arr[0]);
    return 0;
}




