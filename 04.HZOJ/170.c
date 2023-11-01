/*************************************************************************
	> File Name: 170.c
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2023 09:45:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define max 1000

typedef struct words{
    char word[100];
}words;

void dealing(words *s, int n){
    char a[100] = "No_smoking";
    char b[100] = "Ban_smoking";
    char c[1000] = {0};
    for(int i = 0; i < n; i++){
        int l = strlen(s[i].word) % 10;
        while(l--){
            char *m = strstr(s[i].word, b);
            long x = m - s[i].word;
            if(m) {
                strcpy(c, s[i].word + x + strlen(b));
                strcpy(s[i].word + x, a);
                strcat(s[i].word, c);
            }
            
        }
    }
    return ;
}



int main() {
    int n;
    char str[1000] = {0};
    words arrs[max + 5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        strcpy(arrs[i].word, str);
    }
    dealing(arrs, n);
    for(int j = 0; j < n; j++){
        printf("%s\n", arrs[j].word);
    }
    return 0;
}



