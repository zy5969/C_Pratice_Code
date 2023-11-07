/*************************************************************************
	> File Name: 178.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 09:57:31 PM CST
 ************************************************************************/

//第n项字母个数n(n-1)+1
#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 1000000
/*
int fun(int n) {
    char a = 'A';
    if(n == 1) {
        printf("%c", a);
        return 0;
    }
    
    printf("%c", a + 1);
    fun(n - 1);
    return fun(n);
}
*/

int main() {
    int N;
    scanf("%d", &N);
    char str[max + 5] = {'A'};
    for(int j = 1; j < N; j++){
        int s = strlen(str);
        for(int i = 0; i < s; i++){
          //  if(i % 2 != 0) str[i] = 'A';
            str[i] = str[2 * s - i];
        }
        str[s] = 'A' + j;
    }
    printf("%s\n", str);
//    printf("\n");
    return 0;
}



