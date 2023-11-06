/*************************************************************************
	> File Name: 175.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2023 09:26:21 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int N, F;
    int a = 0, b = 0, c = 0, d = 0;
    int arr[30] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &F);
        arr[i] = F;
    }
    for(int i = 0; i < N; i++){
        if(arr[i] >= 90 && arr[i] <= 100) {
            arr[i] = 'Y';
            a++;
        }
        if(arr[i] >= 80 && arr[i] <= 89){
            arr[i] = 'L';
            b++;
        }
        if(arr[i] >= 60 && arr[i] <= 79) {
            arr[i] = 'Z';
            c++;
        }
        if(arr[i] < 60) {
            arr[i] = 'C';
            d++;
        }
    }
    
    printf("You %d\n", a);
    printf("Liang %d\n", b);
    printf("Zhong %d\n", c);
    printf("Cha %d\n", d);
    return 0;
}



