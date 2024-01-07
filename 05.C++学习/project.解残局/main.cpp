/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jan 2024 10:59:22 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <paipk.h>
using namespace std;
#define max 18

string name[max + 5] = {" ", " ", " ", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "king", "KING"};

int main() {
    int x;
    int arr[max + 5] = {0};
    while(cin >> x){
        if(x == 0) break;
        arr[x] += 1;
    }
    
    return 0;
}
