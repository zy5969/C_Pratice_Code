/*************************************************************************
	> File Name: 174.c
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Nov 2023 09:43:49 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>
#define max 1000000
int main() {
    char str[max + 5] = {0};
    char arr[max + 5] = {0};
    int n = 0;
    scanf("%[^\n]", str);
    strcpy(arr, str);
    int l1 = strlen(str), l;

    for(int i = 0; i < l1; i++){
        if(arr[i] == ' ' || arr[i] == '#') {
            arr[i] = '%';
            n++;//空格数
        }
    }
    l = l1 + 2 * n;
    
    for(int j = 0; j < l; j++){
        if(arr[j] == '%' || arr[j] == '#') {
            for(int k = 0; k < l1 - j; k++){
                arr[l1 + 1 - k] = arr[l1 - 1 - k];   
            }
            l1 += 2;
            j += 2;
        }
    }
    for(int i = 0 ; i < l; i++){
        if(arr[i] == '%') {
            arr[i + 1] = '2';
            arr[i + 2] = '0';
        }
    }
    printf("%d\n", n); 
    printf("%d\n", l); 
    printf("%s\n", arr);
    return 0;
}



