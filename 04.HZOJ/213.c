/*************************************************************************
	> File Name: 213.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2023 10:27:18 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int fun(int *a, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]) swap(a[i], a[j]);
        }
    }
    return 0;
}
int count(int *A, int *B, int N){
    for(int j = 0; j < N; j++){
        if(A[j] == 100) B[1]++;
        if(A[j] >= 90 && A[j] <= 99) B[2]++;
        if(A[j] >= 80 && A[j] <= 89) B[3]++;
        if(A[j] >= 70 && A[j] <= 79) B[4]++;
        if(A[j] >= 60 && A[j] <= 69) B[5]++;
        if(A[j] < 60) B[6]++;
    }
    return 0;
}
int main() {
    int N;
    int A[30] = {0}, B[7] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    fun(A, N);
    count(A, B, N);
    for(int i = 0; i < N; i++){
        printf("%d\n", A[i]);
    }
    for(int j = 1; j < 7; j++){
        (j - 1) && printf(" ");
        printf("%d", B[j]);
    }
    printf("\n");
    return 0;
}


