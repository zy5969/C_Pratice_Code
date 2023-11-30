/*************************************************************************
	> File Name: 216.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Nov 2023 10:07:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct Name{
    char name[50];
}Name;

void quick(Name *s, int l, int r){
    if(l > r) return ;
    int a = l, b = r; 
    char c[50] = {0};
    strcpy(c, s[l].name);
    while(a < b){
        while(a < b && strcmp(s[b].name, c) > 0) b--;
        if(a < b) {
            strcpy(s[a].name, s[b].name);
            a++;
        }
        while(a < b && strcmp(s[a].name, c) < 0) a++;
        if(a < b){
            strcpy(s[b].name, s[a].name);
            b--;
        }
    }
    strcpy(s[a].name, c);
    quick(s, l, a - 1);
    quick(s, a + 1, r);
    return ;
}

int main() {
    int n;
    char str[50] = {0};
    Name arr[105] = {0};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        for(int j = 0; j < strlen(str); j++){
           str[j] = str[j + 3]; 
        }
        strcpy(arr[i].name, str);
    }
    quick(arr, 1, n);
    for(int j = 1; j <= n; j++){
        printf("%s\n", arr[j].name);
    }
    return 0;
}



