/*************************************************************************
	> File Name: 145.c
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Oct 2023 08:19:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100] = "";
   // char str2[100] = "";
    char arr[100] = {0};
    int N, a, b = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", str);
        a = strlen(str);
        if(b <= a) {
            b = a;
            strcpy(arr, str);
        } 
        else continue;

        
        //缺少情况:小于前一个数，小于后一个数
       /* if(arr[i] < arr[i + 1]) strcpy(str2, str);
        else continue;
        */
    }
    printf("%s\n", arr);
    return 0;
}




