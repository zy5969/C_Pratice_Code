#include<stdio.h>

int main()
{
    long int n,a1,a2,a3,a4;
    scanf("%ld",&n);
    a1= n/1000;
    a2=n%1000/100;
    a3=n%1000%100/10;
    a4=n%1000%100%10;
    if(a1%2==0 || a2%2==0|| a3%2==0||a4%2==0)
    {
        printf("YES\n");
    }
    else 
        printf("NO\n");
    return 0;
}

