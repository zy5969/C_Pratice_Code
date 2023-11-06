/*************************************************************************
	> File Name: 177.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2023 09:32:39 PM CST
 ************************************************************************/

#include <string.h>
#include<stdio.h>
void swap(char *a, char *b) {
    char p;
    p = *a;
    *a = *b;
    *b = p;
    return ;
}


int main() {
    char str[26] = {0};
    char arr[26] = {0};
    scanf("%s", str);
    strcpy(arr, str);
    int l = strlen(str);
    printf("%s\n", arr);
    for(int n = 0; n < l - 1 ; n++){
        char str1[26] = {0}; 
        for(int i = 0; i < l; i++){
            if(i == l - 2 ) {
                for(int j = i; j > 0; j--){
                    swap(&arr[j], &arr[j - 1]);
                }
            }
            if(i == l - 1) {
                for(int j = i; j > 1; j--){
                    swap(&arr[j], &arr[j - 1]);
                }
            }
        }
       // if(strcmp(arr, str) == 0) break;
        
        printf("%s\n", arr);
        strcpy(str1, arr);
        strcpy(arr, str1);
    }
    
    return 0;
}



