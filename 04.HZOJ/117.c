/*************************************************************************
	> File Name: 117.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 10:13:08 PM CST
 ************************************************************************/
#include<stdio.h>

int main()
{
    int a;
    int a1,a2,a3,a4;
    scanf("%d",&a);

    a1=a/1000;
    a2=a%1000/100;
    a3=a%1000%100/10;
    a4=a%1000%100%10;
    if(a1!=0)
    {
        if(a1==a4&&a2==a3)
             printf("YES\n");
        else
            printf("NO\n");
    }
    if(a1==0&&a2!=0)
    {
        if(a2==a4)
            printf("YES\n");
        else
            printf("NO\n");
    }
    if(a1==0&&a2==0&&a3!=0)
    {
        if(a3==a4)
            printf("YES\n");
        else
            printf("NO\n");
    }
    if(a1==0&a2==0&&a3==0)
        printf("YES\n");
}


