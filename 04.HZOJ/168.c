/*************************************************************************
	> File Name: 168.c
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Oct 2023 09:09:31 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>

typedef struct acod{
    char name[15];
}Name;

void reply(char *s){
    for(int i = 0; i < strlen(s); i++){
        if(i == 0 && s[0] >= 97 && s[0] <= 122) s[0] -= 32;
        if(i > 0 && s[i] >= 65 && s[i] <= 90) s[i] += 32;
    }
}

void quick(Name *arr, int l, int r){
    if(l > r) return ;
    int a = l, b = r; 
    char c[50] = {0};
    strcpy(c, arr[l].name);
    while(a < b){
        while(a < b && strcmp(arr[b].name, c) > 0) b--;
        if(a < b) {
            strcpy(arr[a].name, arr[b].name);
            a++;
        }
        while(a < b && strcmp(arr[a].name, c) < 0) a++;
        if(a < b){
            strcpy(arr[b].name, arr[a].name);
            b--;
        }
    }
    strcpy(arr[a].name, c);
    quick(arr, l, a - 1);
    quick(arr, a + 1, r);
    return ;
}


int main() {
    int n;
    char str[15] = {0};
    Name arr[105] = {0};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        reply(str);
        strcpy(arr[i].name, str);
    }
    quick(arr, 1, n);
    for(int i = 1; i <= n; i++){
        printf("%s\n", arr[i].name);
    }
    return 0;
}


