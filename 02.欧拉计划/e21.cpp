/**************************************************
**亲和数**
记d(n)为n的所有真约数（小于n且整除n的正整数）之和。
如果d(a)=b，d(b)=a，而且a≠b，那么a和b构成一个亲和数对，
a和b都被称为亲和数。
例如，220的真因数包括1、2、4、5、10、11、20、22、44、55
和110，因此d(220)=284；而284的真因数包括1、2、4、71和142，
因此d(284)=220。
求所有小于10000的亲和数之和。 
**************************************************/

#include <stdio.h>
#include <math.h>
#define max 10000

int prime[max + 5];
int cnt[max + 5];//最小素因子幂次
int fun[max + 5];
void num_deal(){
    for(int i = 2; i < max; i++){
        if(!prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = 1;
            fun[i] = 1 + i;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                fun[prime[j] * i] = fun[i] / (pow(prime[j], cnt[j] + 2) - 1);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            } else {
                fun[prime[j] * i] = fun[prime[j]] * fun[i];
                cnt[prime[j] * i] = 1;
                
            }
        }
    }
    return ;
}

int main() {
    num_deal();
    int val = 0;
    for(int i = 2; i < max; i++) fun[i] = fun[i] - i;
    int n = 0;
    for(int i = 2; i < 20; i++){
        if(fun[i] == i ) continue;
      //  if(fun[fun[i]] != i) n++; 
        printf("%d %d\n", i, fun[i]);
        val += i;
    //    printf("i = %d  val = %d  cnt = %d\n", i, val, cnt[i]);
    }
    printf("%d %d\n", n , val);
    return 0;
}

