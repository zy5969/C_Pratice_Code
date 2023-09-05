//字符串长度，查找，插入
#include<iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    int N;
    cin >> A >> N >> B;
    cout << A.size() << endl;
    cout << A.find('a', 0) + 1 << endl;
    A.insert(N - 1, B);
    cout << A << endl;
    return 0;
}

