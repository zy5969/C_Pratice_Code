/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 07:28:41 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/color.h"

int main() {
    int age = 19;
    char name[20] = "test file";
    //调整宏
    DBG("This is Debug information.\\n");
	DBG("%s is %d years old.", name, age);
    //颜色输出
    printf(RED "%s" NONE"\n", name); 
    printf(BLUE "test" NONE"\n");
    printf(PINK "这是粉色" NONE"\n");
    return 0;
}

