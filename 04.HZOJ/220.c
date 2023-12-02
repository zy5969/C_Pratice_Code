/*************************************************************************
	> File Name: 220.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Dec 2023 09:55:00 PM CST
 ************************************************************************/

#include <string.h>
#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct student{
    char name[50];
    int ch, math, en, science;
    int sum;
}student;

void swaps(student *s, int n, int m){
    char str[50] = {0};
    strcpy(str, s[n].name);
    strcpy(s[n].name, s[m].name);
    strcpy(s[m].name, str);
    return ;
}
void insert(student *p, int n, int flag){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            switch(flag){
                case 1:{
                    if(p[j].ch > p[j- 1].ch) {
                        swap(p[j].ch, p[j - 1].ch);
                        swaps(p, j, j - 1);
                    }
                    if(p[j].ch == p[j- 1].ch && strcmp(p[j].name, p[j - 1].name) < 0) swaps(p, j, j - 1);
                }break;
                case 2:{
                    if(p[j].math > p[j- 1].math) {
                        swap(p[j].math, p[j - 1].math);
                        swaps(p, j, j - 1);}
                    if(p[j].math == p[j- 1].math && strcmp(p[j].name, p[j - 1].name) < 0) swaps(p, j, j - 1);
                }break;
                case 3:{if(p[j].en > p[j- 1].en) {
                    swap(p[j].en, p[j - 1].en);
                    swaps(p, j, j - 1);}
                    if(p[j].en == p[j- 1].en && strcmp(p[j].name, p[j - 1].name) < 0) swaps(p, j, j - 1);
                }break;
                case 4:{if(p[j].science > p[j- 1].science) {
                    swap(p[j].science, p[j - 1].science);
                    swaps(p, j, j - 1);}
                    if(p[j].science == p[j- 1].science && strcmp(p[j].name, p[j - 1].name) < 0) swaps(p, j, j - 1);
                }break;
                case 5: {
                    if(p[j].sum > p[j- 1].sum) {
                    swap(p[j].sum, p[j - 1].sum);
                    swaps(p, j, j - 1);}
                    if(p[j].sum == p[j- 1].sum && strcmp(p[j].name, p[j - 1].name) < 0) swaps(p, j, j - 1);
                }break;
            }
        }
    }
    return ;
}

void output(student *a){ 
    for(int i = 0; i < 4; i++){
        i && printf(" ");
        printf("%s", a[i].name);
    }
    printf("\n");
    return ;
}

void repre(student *a, student *b, int n){
    for(int i = 0; i < n; i++){
        a[i] = b[i];
    }
    return ;
}

int main() {
    int n;
    student a[105] = {0};
    student b[105] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", a[i].name);
        scanf("%d", &a[i].ch);
        scanf("%d", &a[i].math);
        scanf("%d", &a[i].en);
        scanf("%d", &a[i].science);
        a[i].sum = a[i].ch + a[i].math + a[i].en + a[i].science;
        b[i] = a[i];
    }
    
    insert(a, n, 1);
    output(a);
    repre(a, b, n);
    insert(a, n, 2);
    output(a);
    repre(a, b, n);
    insert(a, n, 3);
    output(a);
    repre(a, b, n);
    insert(a, n, 4);
    output(a);
    repre(a, b, n);
    insert(a, n, 5);
    output(a);
    
    
    return 0;
}





