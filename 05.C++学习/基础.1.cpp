/*************************************************************************
	> File Name: 基础.1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 10:02:53 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace test {
    void printf(int a, int b) {
        cout << "a + b = " << a + b << endl;
    }
};

int main() {
    int a = 10, b = 12;
    cout << "a + b = " << a + b << endl;
    printf("a + b = %d\n", a + b);
    test::printf(a, b);
    return 0;
}



