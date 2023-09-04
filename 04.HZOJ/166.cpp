#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define max 1000

int main() {
    string A, B;
    int a = 100;
    int N;
    cin >> A >> N >> B;
//    cin >> N ;
 //   cin >> B ;
    //输出长度
    if(A.length() > 100) cout << 100 << endl;
    else cout << A.length() << endl;
    A.insert(N - 1, B);//在A中插入字符串
    cout << A << endl;
    //
    reverse(A.begin(), A.end());
   //查找，查找结果为空时输出-1，字符下标由1开始，查找下标0开始 
    if(A.find('x') == std::string::npos) cout << -1 << endl;
    else cout << A.find('x') + 1 << endl;
    return 0;
}


