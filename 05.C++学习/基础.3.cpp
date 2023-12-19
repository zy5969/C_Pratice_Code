/*************************************************************************
	> File Name: 基础.3.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 02:17:55 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>

//自定义类型
typedef struct node {
    int a;
    float b;
}node;

using namespace std;

namespace Test {
    void vec(int *arr) {

    }
}


int main() {
    vector<int> v1; //初始化为空
    vector<int> v2(10);//初始化规模
    vector<int> v3(3, 8);//范围
    vector<int> v4 = {1, 2, 3, 4, 5};//指定元素
    int arr[] = {1, 3, 5, 7, 9};
    vector<int> v5(arr + 1, arr + 4);
    //二维容器,4行，5列，数值为5
    vector<vector<int> > v(4, vector<int>(5, 5));
    //返回元素个数
    cout << "v4.size = " << v4.size() << endl;
    v4.push_back(50);
    cout << "v4.size2 = " << v4.size() << endl;
    //判断是否为空
    if(v4.empty()) {
        cout << "v4 is empty!" << endl;
    } else cout << "v4 is not empty!" << endl;
    //插入,借助迭代器
    v4.insert(v4.begin() + 2, 20);

    //打印v4
    cout << "v4: ";
    for(int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    //使用迭代器访问
    cout << "迭代器访问: " ;
    //auto i 可替换vector<int>::iterator i
    for(vector<int>::iterator i = v4.begin(); i != v4.end(); i++){
        cout << *i << " ";//输出对应地址的值
    }
    cout << endl;

    //输出二维容器
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    //使用自定义类型
    vector<node> b;
    b.push_back((node){1, 1.23});
    b.push_back((node){2, 3.5});
    b.push_back((node){3, 4.2});
    cout << b.size() << endl;

    return 0;
}


