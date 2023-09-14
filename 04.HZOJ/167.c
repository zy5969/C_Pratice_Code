#include <string.h>
#include <stdio.h>
#define max 10000

int main() {
    char A[max] = {0}, B[max] = {0};
    char arr1[max + 5] = {0}, arr2[max + 5] = {0};
    int N, d = 0;
    scanf("%s\n%d\n%s", A, &N, B);
    strcpy(arr1, A);
    strcpy(arr2, B);
    int l = strlen(A);
    printf("%d\n", l);
    
    for(int j = 0 ; j < l; j++){
        d++; 
        if(arr1[j] == 'a')  break;
    }
    printf("%d\n", d);
    
    l = l + strlen(B);
    for(int i = l - 1; i > N - 1; i--){
        arr1[i] = arr1[i - strlen(B)]; 
    }
    for(int k = N - 1, j = 0; k < N - 1 + strlen(B), j < strlen(B); k++, j++){
        arr1[k] = arr2[j];
    }

    printf("%s\n", arr1);
    return 0;
}


