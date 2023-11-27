/*************************************************************************
	> File Name: 210.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Nov 2023 11:12:19 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>


typedef struct word{
    char str[10];
}word;

void quick(word *num, int l, int r){
if(r < l) return ;
    int x = l,y = r;  
    while(x < y) {
        while(x < y && strcmp(num[y].str, num[l].str) <= 0) y--;
        if(x < y) {
            strcpy(num[x].str , num[y].str);
            x++;
        }
        while(x < y && strcmp(num[x].str, num[l].str) >= 0) x++;
        if(x < y){
            strcpy(num[y].str , num[x].str);
            y--;
        }
    }
    strcpy(num[x].str, num[l].str);
    quick(num, l, x - 1);
    quick(num, x + 1, r);
    return ;
}


void insert(word *s, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(strcmp(s[j].str, s[j - 1].str) < 0) {
                char a[10] = {0};
                strcpy(a, s[j].str);
                strcpy(s[j].str, s[j - 1].str);
                strcpy(s[j -1].str, a);
            }
        }
    }
    return ;
}


int main() {
    int N;
    word words[30] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", words[i].str);
    }
 //   insert(words, N);
    quick(words, 0, N);
    for(int j = 0; j < N; j++){
        j && printf(" ");
        printf("%s", words[j].str);
    }
    printf("\n");
    return 0;
}



