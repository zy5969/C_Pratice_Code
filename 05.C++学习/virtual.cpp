/*************************************************************************
	> File Name: virtual.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 08:18:36 PM CST
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;

class USB_interface{
public:
    virtual string get() = 0;
    virtual void set(string) = 0;
};

class KeyBoard : public USB_interface{
public :
    string get() {
        return "keyborad";
    }
    void set(string msg) {
        cout << "Key borad rece" << msg << endl;
        return;
    }
};

class Mouse : public USB_interface {
public:
    string get() {
        return "this message come from mouse";
    }
    void set(string msg){
        cout << "mouse rece" << msg << endl;
        return ;
    }
};

int main() {
    string s1, s2;
    KeyBoard key;
    Mouse mouse;
    s1 = key.get();
    key.set(s1);
    s2 = mouse.get();
    mouse.set(s2);
    return 0;
}

