#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 200000
#define MIN_VALUE 0
#define MAX_VALUE 1919180

int main() {
    int randomArray[ARRAY_SIZE];
    int i;

    // 使用114514作为随机数生成的种子
    srand(114514);

    // 生成随机数组
    for (i = 0; i < ARRAY_SIZE; i++) {
        randomArray[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
    }

    // 打印随机数组
    printf("Random Array: \n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", randomArray[i]);
    }
    printf("\n");

