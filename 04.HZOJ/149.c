/*************************************************************************
	> File Name: 149.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Oct 2023 09:20:09 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>
//空格获取
int main() {
    char str[51] = "";
    char arr[51] = {0};
    int a = 0;
    scanf("%[^\n]", str); 
    
    strcpy(arr, str); 
    for(int i = 0; i < strlen(str); i++) {
        a++;
        if(arr[i] == ' ') a = 0;
    }
    
    printf("%d\n", a);
    return 0;
}



