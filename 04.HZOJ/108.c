//三角形面积
#include<stdio.h>

int main()
{
    char s;
    double m,n;
    scanf("%s\n",&s);
    scanf("%lf%lf",&n,&m);
    if(s=='r')
    {
        printf("%.2f\n",n*m);
    }
    if(s=='t')
    {
        printf("%.2f\n",(n*m)/2);
    }
    
    return 0;
}

