#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 200000 // 定义数组大小

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // 初始化最大元素的索引为根索引
    int left = 2 * i + 1; // 左子节点的索引
    int right = 2 * i + 2; // 右子节点的索引

    // 如果左子节点大于根节点，则更新最大元素的索引
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于当前最大元素，则更新最大元素的索引
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大元素的索引不是根索引，则交换它们，并继续堆化子树
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 构建堆（从最后一个非叶子节点开始，到根节点）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 从堆中提取元素并排序
    for (int i = n - 1; i >= 0; i--) {
        // 将当前根（最大值）与最后一个元素交换
        swap(&arr[0], &arr[i]);
        // 堆化从根到新的末尾元素的子树
        heapify(arr, i, 0);
    }
}

void swapFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyFloat(float arr[], int n, int i) {
    int largest = i; // 初始化最大元素的索引为根索引
    int left = 2 * i + 1; // 左子节点的索引
    int right = 2 * i + 2; // 右子节点的索引

    // 如果左子节点大于根节点，则更新最大元素的索引
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于当前最大元素，则更新最大元素的索引
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大元素的索引不是根索引，则交换它们，并继续堆化子树
    if (largest != i) {
        swapFloat(&arr[i], &arr[largest]);
        heapifyFloat(arr, n, largest);
    }
}

void heapSortFloat(float arr[], int n) {
    // 构建堆（从最后一个非叶子节点开始，到根节点）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyFloat(arr, n, i);

    // 从堆中提取元素并排序
    for (int i = n - 1; i >= 0; i--) {
        // 将当前根（最大值）与最后一个元素交换
        swapFloat(&arr[0], &arr[i]);
        // 堆化从根到新的末尾元素的子树
        heapifyFloat(arr, i, 0);
    }
}

int main() {
    int i;
    int intArray[ARRAY_SIZE];
    float floatArray[ARRAY_SIZE];
    srand(114514); // 使用114514作为随机数种子

    // 生成整型随机数组
    printf("整型随机数组:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        intArray[i] = rand() % 114514; // 生成0到114513之间的随机整数
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // 使用堆排序对整型数组进行排序
    heapSort(intArray, ARRAY_SIZE);

    printf("排序后的整型数组:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    // 生成浮点数随机数组
    printf("浮点数随机数组:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        floatArray[i] = (float)rand() / (RAND_MAX / 1919180); // 生成0到1919180之间的随机浮点数
        printf("%.2f ", floatArray[i]);
    }
    printf("\n");

    // 使用堆排序对浮点数数组进行排序
    heapSortFloat(floatArray, ARRAY_SIZE);

    printf("排序后的浮点数数组:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%.2f ", floatArray[i]);
    }
    printf("\n");

    return 0;
}
