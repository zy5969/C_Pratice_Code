/*************************************************************************
	> File Name: 基础.2.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 02:25:15 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//自定命名空间Test, 默认std

namespace Test{
    void timeout(int n, int m) {
        cout << "time : " << n << ":" << m << endl;
    }
    void strs(string str, string str2){
        cout << "length:   " << str.length() << endl;
        cout << "size:     " << str.size() << endl;
        cout << "find d:   " << str.find('d', 0) << endl;
        cout << "insert 3: " << str.insert(3, str2) << endl;
        cout << "erase3/2: " << str.erase(3, 2) << endl;
        cout << "substr3/2:" << str.substr(3, 2) << endl;
        cout << "replace24:" << str.replace(2, 4, str2) << endl;
    }
};

int main() {
    int a , b ;
    cout << "Enter the number of hours: " ;
    cin >> a;
    cout << "Enter the number of minute: " ;
    cin >> b;
    Test::timeout(a, b);
//    cout << "time: " << a << " : " << b << endl;
    //格式化输出
    char ch = 'A';
    int n = 100;
    string str = "abcdefgabdeg";
    
    double dull = 1.23;
    cout << "char : " << ch << endl;
    cout << "int : " << n << endl;
    cout << "string : " << str << endl;
    cout << "double : " << dull << endl;
    cout << "float : " << 1.0230 << endl;
    
    double d1 = 1.45e3;
    cout << "d1 : " << d1 << endl;
    double d2 = 2.3e-3;
    cout << "d1 : " << d2 << endl;
    double d3 = 1.53e7;
    cout << "d1 : " << d3 << endl;
    
    //字符操作
    string str2 = "abcd";
    string str1 = "abcdefrandbcegt";
    cout << str1 << endl;
  //  cout << "insert 3: " << str1.insert(3, str2) << endl;
    Test::strs(str1, str2);//执行后字符串不变
 //   int begin = str1.begin();
    //输出首尾字符
    cout << "begin: " << *str1.begin() << endl;
    cout << "end: " << *(str1.end() - 1) << endl;
    cout << str1 << endl;
    reverse(str1.begin(), str1.end());
    cout << "reverse:  " << str1 << endl;
    return 0;
}

