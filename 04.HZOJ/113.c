//年月分天数
#include<stdio.h>

int main() {

    int y, m;
    scanf("%d%d", &y, &m);
  
        switch(m) {
            case 1:printf("30\n");break;
            case 2:if((y%4 == 0 && y%100 != 0) || y%400==0) printf("29\n");
                   // if(y%400 == 0) printf("29\n");
            else printf("28\n");
            break;
            case 3:printf("31\n");break;
            case 4:printf("30\n");break;
            case 5:printf("31\n");break;
            case 6:printf("30\n");break;
            case 7:printf("31\n");break;
            case 8:printf("31\n");break;
            case 9:printf("30\n");break;
            case 10:printf("31\n");break;
            case 11:printf("30\n");break;
            case 12:printf("31\n");break;
        }
    

    return 0;
    }

