#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//结构定义
typedef struct vector {
    int *data;
    int size, length;//大小、个数

}vector;
int expand(vector *vec);

//初始化
vector *init(int n) {
    vector *vec = (vector *)malloc(sizeof(vector));//表示初始化的顺序表
    vec->data = (int *)malloc(sizeof(int ) * n);//data动态初始化*
    vec->size = n;//size
    vec->length = 0;//length
    return vec;
}
//插入 ind:下标即位置 
int insert(vector *vec, int ind, int val) {
    //判断参数合法性
    if(vec == NULL) return 0;  //顺序表是否为空
    if(ind < 0 || ind > vec->length) return 0;  //插入位置
    if(vec->length == vec->size) {
        if(!expand(vec)) return 0;
        printf("\033[31mexpand success\n\033[0m");//\033[31 设置输出字体颜色为红色
    }
    for (int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];  //i移动到插入位置的下一个位置     
    }
    vec->data[ind] = val;//更新结构
    vec->length++;//元素个数增加
    return 1;
}

//删除操作，向前移动
int delete(vector *vec, int ind) {
    //判断合法性
    if(vec == NULL) return 0;
    if(ind < 0 || ind >= vec->length) return 0;//不能删除空的位置
    for(int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length--;//更新
    return 1;
}
//输出
void output(vector *vec) {
    for(int i = 0;i < vec->length; i++) {
        printf("%d ", vec->data[i]);//遍历数据表、输出
    }
    printf("\n");
    return ;
}
//清空
void clear(vector *vec) {
    if(vec == NULL) return ;//判断表是否为空
    if(vec->data != NULL) {
        free(vec->data);//数据清空
    }
    free(vec);
    return ;
}
//扩容readlloc 扩充之前分配的内存块
//先扩2倍
int expand(vector *vec) {
    int exp_size = vec->size;//当前扩展的内存赋值为原本内存大小
    int *exp_vec = (int *)realloc(vec->data,sizeof(int) * exp_size * 2); //新的容量
  /*  //折半扩容，每次增加一半
    int *exp_vec ;
    while(exp_size) {
        exp_vec = (int *)realloc(vec->data,sizeof(int) * (vec->size + exp_size));
        if(exp_vec) break;
        exp_size /= 2;
    } */
    if(exp_vec == NULL) return 0;//判断是否成功
    vec->data = exp_vec;//数据存储空间更新
    vec->size *= 2;//更新顺序表大小为两倍
    return 1;
}

int main () {
    srand(time(0));//定义随机数、进行插入、删除
    vector *vec = init(1);//初始化
    int op;//0、1、2插入，3删除
    int ind, val;//插入位置、值
    for(int i = 2; i < 20; i++) {
    op = rand() % 4;//产生随机数0.1.2.3
    ind = rand() % (vec -> length + 1);
    val = rand() % 100;//100以内随机数
    switch(op) {
        case 0:
        case 1:
        case 2:printf("insert\n"); insert(vec, ind, val);output(vec); break;
        case 3:printf("delete\n"); delete(vec, ind);output(vec); break;

    }
}
 clear(vec);

    return 0;

}
