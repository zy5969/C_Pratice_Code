/*************************************************************************
	> File Name: 120.c
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Oct 2023 09:47:22 PM CST
 ************************************************************************/

#include <stdio.h>
//#include <time.h>
int date(int y, int m, int d) {
    if(y <= 0 || m <= 0 || d <= 0) return 0;
    if(m > 12 || d > 31) return 0;
    if(m == 2) {
        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ) {
            if(d <= 29) return 1;
            else return 0;
        }
        if(d <= 28) return 1;
        else return 0;
    }
    
  //  int i = rand() % 3, j = rand() % 7;
    int arr1[7] = {1, 3, 5, 7, 8, 10, 12};
    int arr2[4] = {4, 6, 9, 11};
    for(int i = 0; i < 4; i++) {
        if( m == arr2[i] && d <=30) return 1;
    }
    for(int i = 0; i < 7; i++) {
        if(m == arr1[i] && d <= 31) return 1;
    }
    return 0;
}


int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if(date(y, m, d)) printf("YES\n");
    else printf("NO\n");
    return 0;
}


