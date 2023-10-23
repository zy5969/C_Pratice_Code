/*************************************************************************
	> File Name: 159.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 08:04:29 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char a;
    scanf("%c", &a);
    for(int i = a; i >= 'A'; i--){
        char b = i;
        for(int k = 0; k < a - i; k++){
            printf(" ");
        }
        for(int j = 2 * (i - '@') - 1; j > 0; j--){
            if(b == '@') b = 'A';
            printf("%c", b);
            if(j < i - '@') {
                b++;
            }
            else b--;
        }

        printf("\n");
       // printf("%d\n", 'a');
    }
    return 0;
}





