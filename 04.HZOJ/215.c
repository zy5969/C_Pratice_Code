/*************************************************************************
	> File Name: 215.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Nov 2023 10:49:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int fun(int *a, int *name, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int putname(char *str, int x){
	for(int i = 0; i < x; i++){
	//	if(str[i] == 1) return 0;
		printf("%c", str[i]);
	}
	
	return 0;
}

int main() {
    int n, d, arr[40] = {0};
    char str[10] = {0};
    char strs[400] = {0};//名字
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int s = 0;
        for(int j = 0; j < 4; j++){
            scanf("%d", &d);
            s += d;//分数总和
        }
        arr[i] = s;
        int k = strlen(strs);
        for(int l = 0; k <= strlen(str); k++, l++){
            if(k < strlen(str)) strs[k] = str[l];
            else strs[k] = i + 1;
        }
        
    }
    for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
    int c = strlen(strs);
	putname(strs, strlen(strs));
	printf("\n%d \n", c);
    return 0;
}

