#include<stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    if(N<=3)
    {
        printf("%d\n",13+1);
    }
    if(N>3)
    {
        printf("%.1f\n",(N-3)*2.3+13+1);
    }
    return 0;

}

