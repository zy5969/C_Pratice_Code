/*************************************************************************
大整数加法,100个50位的数字和
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char str[55];//每50位以字符串输入
int arr[55];//读入的数加入arr

int main() {
    for(int i = 0; i < 100; i++){
        scanf("%s", str);
        int l = strlen(str);
        if(arr[0] < l) arr[0] = l;
        //到着加入arr,方便处理最高位进位，向后扩展数组
        for(int j = 0; j < l; j++){
            arr[l - j] += (str[j] - '0');
        }
        //处理进位
        for(int k = 1; k <= arr[0]; k++){
            if(arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;//有进位，加上前一位的进位
            arr[k] %= 10;//有进位当前位存余数
            arr[0] += (k == arr[0]);//最高位进位
        }
    }
    printf("%d\n", arr[0]);
    for(int a = arr[0]; a > arr[0] - 10; a--){
        printf("%d", arr[a]);
    }
    printf("\n");
   return 0;
}

