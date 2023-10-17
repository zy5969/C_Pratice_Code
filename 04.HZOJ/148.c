/*************************************************************************
	> File Name: 148.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Oct 2023 09:47:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main() {
    char str[50] = "";
    char arr[50] = {0};
    scanf("%s", str);
    strcpy(arr, str);
    for(int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    printf("\n");

    return 0;
}



