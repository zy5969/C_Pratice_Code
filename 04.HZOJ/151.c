/*************************************************************************
	> File Name: 151.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Oct 2023 08:24:50 PM CST
 ************************************************************************/

#include <stdio.h>

//判断输赢li 2, MING 1, 3 
int win(char a, char b) {
    if(a=='O'){
        if(b=='O') return 3;
        if(b=='Y') return 1;
        if(b=='H') return 2;

    }
    if(a=='Y'){
        if(b=='O') return 2;
        if(b=='Y') return 3;
        if(b=='H') return 1;
    }
    if(a=='H'){
        if(b=='O') return 1;
        if(b=='Y') return 2;
        if(b=='H') return 3;
    }
}

int main() {
    char l1, r1, l2, r2;
    int m;
    scanf("%s%s%s%s", &l1, &r1, &l2, &r2);
    
    if(win(l1, l2) == 1) {
        if(win(l1, r2) == 3 || win(l1, r2) == 1) m = 1;
        else {
            if(win(r1, r2) == 1) m = 1; 
            else m = 2;
        }
    }
    else if(win(l1,l2) == 3) {
        if(win(r1, r2) == 1)  m = 1;
        else if(win(r1, r2) == 2) m = 2; 
        else  m = 3; 
    }
    else if(win(l1,l2) == 2) {
        if(win(r1, l2) == 3 || win(r1, l2) == 2) m = 2;
        else {
            if(win(r1, r2) == 3 || win(r1, r2) == 1) m = 1; 
            else m = 2;
        }
    }
  
    switch(m){
        case 1:printf("NING\n"); break;
        case 2:printf("LIHUA\n"); break;
        case 3:printf("TIE\n");break;
    }
    return 0;
}




