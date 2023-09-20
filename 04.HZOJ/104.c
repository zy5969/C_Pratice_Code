//各位是否有9
#include<stdio.h>

int main() {
    int a,a1,a2,a3;
    scanf("%d", &a);
    a1=a / 100;
    a2=a % 100 / 10;
    a3=a % 100 % 10;
    if(a1 == 9 || a2 == 9 || a3 == 9) printf("YES");
    
    else printf("NO");
    return 0;
}

