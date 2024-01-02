/*************************************************************************
	> File Name: OJ881.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Jan 2024 09:57:01 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Swap {
public:
    void swap(int *a, int *b){
        int *c = a; 
  //      this->a = a;
  //      this->b = b;
        *a = *b;
        *b = *c;
        cout << *a << " " << *b  << " " << *c << endl;
    }
//   int *a, *b; 
};

int main() {
    int a, b;
    cin >> a >> b;
    Swap s;
    s.swap(&a, &b);
    return 0;
}

