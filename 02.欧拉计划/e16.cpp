/*************************************************************************
幂的数字和
215=32768，而32768的各位数字之和是 3+2+7+6+8=26。
21000的各位数字之和是多少？
 ************************************************************************/

#include <stdio.h>
#define max 400

int arr[max + 5];
int main() {
    arr[0] = arr[1] = 1;

    for(int i = 0; i < 100; i++){
        for(int j = 1; j <= arr[0]; j++) arr[j] *= 1024;
        for(int k = 1; k <= arr[0]; k++){
            if(arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;
            arr[k] %= 10;
            arr[0] += (k == arr[0]);
        }
    }
    int val = 0;
    for(int i = arr[0]; i > 0; i--){
        val += arr[i];
    }
    printf("%d\n", val);
    return 0;
}

