/*************************************************************************
	> File Name: 147.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 08:30:55 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>

int main() {
    char str[10000] = "";
    char arr[10000] = {0};
    scanf("%s", str);
    strcpy(arr, str);
    if(arr[strlen(str) - 1] % 2 == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}



