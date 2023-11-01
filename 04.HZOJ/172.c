/*************************************************************************
	> File Name: 172.c
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2023 09:47:06 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>

typedef struct Name {
    char str[25];
}Name;

void insert(Name *a){
    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            if(strcmp(a[i].str, a[j].str) > 0) {
                char s[25] = {0};
                strcpy(s, a[i].str);
                strcpy(a[i].str, a[j].str);
                strcpy(a[j].str, s);
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

