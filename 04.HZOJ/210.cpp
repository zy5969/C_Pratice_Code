/*************************************************************************
	> File Name: 210.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Nov 2023 11:13:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include<iostream>
using namespace std;

int main() {
    int n;
    char str[30] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    for(int j = 0; j < n; j++){
        j && printf(" ");
        cout << str[j];
    }
    printf("\n");
    return 0;
}


