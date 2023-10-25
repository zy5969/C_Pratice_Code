/*************************************************************************
	> File Name: 169.c
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Oct 2023 09:10:41 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>

int main() {
    int N, y;
    int arr[50] = {0};//字母对应数字
    char str1[50] = {0};//字母
    char str2[50] = {0};//字符串前N个字母
    char str[50] = {0};//密码
    int a = 0;
    scanf("%d", &N);
    for(int i = 0; i < 2 * N; i++){
        int ch ; 
        scanf("%d\n", &y);//2n行
        ch = getchar();
        if(i < N) str1[i] = ch;
        else str2[i - N] = ch;
       // if(i % 2 != 0){
            arr[i] = y;
           // a++;
       // }
        
    }
    scanf("%s", str);//密码
    int num = 0;
    int s = 0;
 //   printf("%d\n", a);
/*    for(int i = 1; i < N + 1; i++){
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < 2 * N; i++){
        printf("%c ", str1[i]);
    }
   */ for(int i = 0; i < N; i++){
        for(int j = 0; j < strlen(str); j++){
            if(str1[i] == str[j]) s += arr[i + 1];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < strlen(str2); j++){
            if(str1[i] == str2[j]) s += arr[i + 1];
        }
    }

    printf("%d\n", s + num); 
    return 0;
}


