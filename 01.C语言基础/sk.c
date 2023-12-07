/*************************************************************************
	> File Name: sk.c 多组数据综合处理
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct cases { 
    int time, m;
    char ah, color;
} cases;

typedef struct anser{
    char *s;
    int T, M;
}anser;

 

//处理整个数据组
void dealing(cases *data, anser *put, int n, char *s1, char *s2){
    //取红色牌
    int a = 0;
    for(int i = 0; i < n; i++){ 
        if(data[i].color == 'r') {
            if(data[i].ah == 'h') put[a].s = s1;
            else put[a].s = s2;
            put[a].T = data[i].time;
            put[a].M = data[i].m;
            a++;
        }
        //黄色
    }
    return ;
}
//结果输出
void output(anser *put){
    
    return;
}

int main() {
    int n;
    char s1[20] = {0}, s2[20] = {0};
    cases data[100] = {0};
    anser put[100] = {0};
    scanf("%s%s%d", s1, s2, &n);
    for(int i = 0; i < n; i++){
        scanf("%d%s", &data[i].time, &data[i].ah);
        scanf("%d%s", &data[i].m, &data[i].color);
    }
    printf("\n");
    for(int j = 0; j < n; j++){
        printf("%d %c %d %c\n", data[j].time, data[j].ah, data[j].m, data[j].color);
    }
    dealing(data, put, n, s1, s2);
    output(put);
    return 0;
}


