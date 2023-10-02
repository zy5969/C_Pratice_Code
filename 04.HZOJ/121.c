/*************************************************************************
	> File Name: 121.c
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Oct 2023 10:29:23 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
    char a,b;
    scanf("%s%s",&a,&b);
    if(a=='O')
    {
        if(b=='O')
            printf("TIE\n");
        if(b=='Y')
            printf("MING\n");
        if(b=='H')
        printf("LI\n");

    }
    if(a=='Y')
    {
        if(b=='O')
        printf("LI\n");
        if(b=='Y')
            printf("TIE\n");
        if(b=='H')
            printf("MING\n");
    }
    if(a=='H')
    {
        if(b=='O')

            printf("MING\n");
        if(b=='Y')
            printf("LI\n");
        if(b=='H')
            printf("TIE\n");
    }

    return 0;
}


