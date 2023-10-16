/*************************************************************************
	> File Name: 146.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Oct 2023 08:29:46 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>

int main() {
    char str[50] = "";
    char arr[50] = {0};
    scanf("%s", str);
    strcpy(arr, str);
    for(int i = 0; i < strlen(str); i++) {
        if((arr[i] >= 0x41 && arr[i] < 0x5a) || (arr[i] >= 0x61 && arr[i] < 0x7a)) arr[i] += 1;
        else if(arr[i] == 0x5a) arr[i] = 0x41;
        else if(arr[i] == 0x7a) arr[i] = 0x61;

    }
    printf("%s\n", arr);

    return 0;
}




