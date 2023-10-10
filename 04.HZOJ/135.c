/*************************************************************************
	> File Name: 135.c
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Oct 2023 09:25:59 PM CST
 ************************************************************************/

//d+x<=31||30 
//m 1~2,2~3,3~4||5~6||8~9||10~11,4~5||6~7||9~10||11~12,7~8 
//d+x>31  






#include <stdio.h>

int year(int y){
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
    else return 0;
}

int mouth(int m, int y){

    if(m == 1|| m == 3|| m == 5|| m == 7|| m == 8|| m == 10 || m == 12) return 31;
    if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
    if(m == 2 && year(y) == 0) return 28;
    if(m == 2 && year(y) == 1) return 29;
}

int day(int m, int y){
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:return 31;
        case 4:
        case 6:
        case 9:
        case 11:return 30;
        case 2:{
            if(year(y) == 0) return 28;
            else return 29;
        }
    }
    
}


int main() {
    int x, y, m, d;
    scanf("%d%d%d%d", &x, &y, &m, &d);
    int t = x + d;
    while(t > mouth(m, y)) {
        t = t - mouth(m, y);
        m++;
        if(m == 13){
            m = 1;
            y++;
        }
    }
    printf("%d %d %d\n", y, m, t);
    return 0;
}




