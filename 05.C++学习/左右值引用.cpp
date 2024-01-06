/*************************************************************************
	> File Name: 左右值引用.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jan 2024 08:10:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//左值引用&
void left_right(int &x){
    printf("left val : %d\n", x);
    return ;
}
//右值引用&&
void left_right(int &&x){
    printf("right val : %d\n", x);
    return ;
}

class Array {
public :
  //  Array();
};

int main() {
    int a = 12;
    left_right(a);
    left_right(a + 1);
    left_right(1);
    return 0;
}


