/*************************************************************************
	> File Name: 173.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Nov 2023 10:41:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define max 1000

int main() {
    char str[max + 5] = "";
    char arr[max + 5] = {0};
    scanf("%[^\n]", str);
    strcpy(arr, str);
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < strlen(str); i++){
        if(arr[i] <= '9' && arr[i] >= '0') b++;
        else if(arr[i] == ' ') c++;
        else if((arr[i] >= 'a' && arr[i] <= 'z') ||(arr[i] >='A' && arr[i] <= 'Z')) a++;
        else d++;
    }
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}



