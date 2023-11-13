/*************************************************************************
	> File Name: 191.c
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Nov 2023 07:27:16 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int arr[max_n + 5] = {1, 1};
int prime() {
    for(int i = 2; i < max_n; i++){
        if(arr[i]) continue ;
        for(int j = i, I = max_n / i; j <= I; j++){
            arr[i * j] = 1;
        }
    }
    return 1;
}

int main() {
    prime();
    int l, r;
    int x1 = 0, x2, y1, y2;
    scanf("%d%d", &l, &r);
    for(int i = l; i < r;i++){
        if(!arr[i]) {
            int n = i + 1;
            while(arr[n]) n++;
            if(n > r) break;
            if(x1 == 0) {
                x1 = i;
                x2 = n;
                y1 = x1;
                y2 = x2;
            }
            else if(x2 - x1 > n - i) {
                x1 = i;
                x2 = n;
            }
            else if(y2 - y1 < n - i) {
                y2 = n;
                y1 = i;
            }
        }
    }
    if(x1 == 0) printf("There are no adjacent primes.\n");
    else printf("%d,%d are closest, %d,%d are most distant.\n", x1, x2, y1, y2);
    return 0;
}



