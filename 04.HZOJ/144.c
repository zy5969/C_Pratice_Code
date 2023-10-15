/*************************************************************************
	> File Name: 144.c
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Oct 2023 08:18:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main () {
    char str[100] = "";
    char arr[100] = {0};
    int n = 0;
    scanf("%s", str);
    strcpy(arr, str);
    for(int i = 0; i < strlen(str); i++) {
        if(arr[i] == 0x41) n += 1;
    }
    printf("%d\n", n);
    return  0;
}



