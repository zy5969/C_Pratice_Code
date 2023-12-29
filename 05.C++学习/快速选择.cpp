/*******************************************
	> File Name: 快速选择.cpp
	> Author: 
	> Mail: 
	> Thu 21 Dec 2023 11:02:50 AM CST
 *******************************************/

#include<iostream>
#include<algorithm>
using namespace std;

void swap(int *a, int *b){
    int *c = a;
    *a = *b;
    *b = *c;
    return ;
}

int midval(int a, int b, int m){
    if(a < b) swap(a , b);
    if(b < m) swap(b, m);
    return b;
}

//类似nth_element(first, nth, last)
//实现获取第nth大的数
void nth_element(int *first, int *nth, int *last){
    if(last - first == 1) return ;
    int *a = first, *b = last - 1;
    int n = midval(*a, *b, *(first + (last - first) / 2));
    do{
        while(*a < n) ++a;
        while(*b > n) --b;
        if(a <= b) {
            swap(*a, *b);
            --a, ++b;
        }
    }while(a <= b);
    if(nth <= b) nth_element(a, nth, b + 1);
    else nth_element(b + 1, nth, b);
    return ;
}

void output(int *arr, int n){
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {0};
    srand(time(0));
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
    output(arr, 10);
    nth_element(&arr[0], &arr[5], &arr[9]);
    output(arr, 10);
    return 0;
}

