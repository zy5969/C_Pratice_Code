/*************************************************************************
	> File Name: 122.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Oct 2023 08:56:24 PM CST
 ************************************************************************/

#include <stdio.h>

int main()
{
    int t;

    scanf("%d",&t);
    
    if(t<43200)
    {
         printf("%02d:%02d:%02d am\n",t/3600,t%3600/60,t%3600%60);
    }
   else if(t>=43200&&t<=46800)
    {
        printf("12:%02d:%02d midnoon\n",t%3600/60,t%3600%60);

    }
   else if(t>46800)
    {
        printf("%02d:%02d:%02d pm\n",(t-46800)/3600+1,(t-46800)%3600/60,(t-46800)%3600%60);
    }
    
    return 0;
}

