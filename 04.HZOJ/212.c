/*************************************************************************
	> File Name: 212.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2023 10:26:38 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>

typedef struct Name {
    char str[25];
}Name;

void insert(Name *a){
    for(int i = 1; i < 10; i++){
        for(int j = i; j > 0; j--){
            if(strcmp(a[j].str, a[j - 1].str) < 0) {
                char s[25] = {0};
                strcpy(s, a[j].str);
                strcpy(a[j].str, a[j - 1].str);
                strcpy(a[j - 1].str, s);
            }
        }
    }
    return ;
}


int main() {
    Name name[10] = {0};
    for(int i = 0; i < 10; i++){
        scanf("%s", name[i].str);
    }
    insert(name);
    for(int j = 0; j < 10; j++){
        printf("%s\n", name[j].str);
    }
    return 0;
}


