/*************************************************************************
	> File Name: 181.c
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 08:59:05 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>
#define max 1000
int swap(char *s){
    
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
        else if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    
    return 0;
}

int main() {
    
    char str[max + 5] = "";
    char arr[max + 5] = {0};
    scanf("%s", str);
    strcpy(arr, str);
    swap(arr);
    printf("%s\n", arr);
    return 0;
}



