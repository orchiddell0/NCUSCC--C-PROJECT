#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 200000
#define MAX_DEGREE 50 // 假设最大度数为20

typedef struct Node {
    int key;
    struct Node *parent, *child, *left, *right;
    int degree; // 子节点的数量
    int mark; // 是否有子节点被删除过
} Node;

typedef struct FibonacciHeap {
    Node *min;
    Node *root;
    int size;
} FibonacciHeap;

// 创建一个新的节点
Node* createNode(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->parent = node->child = node->left = node->right = NULL;
    node->degree = 0;
    node->mark = 0;
    return node;
}

// 创建一个新的斐波那契堆
FibonacciHeap* createFibonacciHeap() {
    FibonacciHeap *heap = (FibonacciHeap *)malloc(sizeof(FibonacciHeap));
    heap->min = NULL;
    heap->root = NULL;
    heap->size = 0;
    return heap;
}

// 插入节点到斐波那契堆
void insert(FibonacciHeap *heap, Node *node) {
    if (heap->min == NULL) {
        heap->min = node;
        node->left = node->right = node;
    } else {
        node->left = heap->min;
        node->right = heap->min->right;
        heap->min->right->left = node;
        heap->min->right = node;
    }
    heap->size++;
}

// 提取最小元素
Node* extractMin(FibonacciHeap *heap) {
    Node *z = heap->min;
    if (z != NULL) {
        if (z->child != NULL) {
            Node *child = z->child;
            while (child != NULL) {
                Node *brother = child->right;
                child->parent = NULL;
                insert(heap, child);
                child = brother;
            }
        }
        if (z->left == z) {
            heap->min = NULL;
        } else {
            heap->min = z->right;
            z->left->right = z->right;
            z->right->left = z->left;
        }
        if (heap->root != NULL) {
            Node *y = heap->root;
            while (y != NULL) {
                if (y != z && y->mark == 1) {
                    Node *x = y->child;
                    while (x != NULL) {
                        x->parent = NULL;
                        insert(heap, x);
                        x = x->right;
                    }
                    y->child = NULL;
                    y->mark = 0;
                }
                Node *brother = y->right;
                if (y->degree < heap->min->degree) {
                    heap->min = y;
                }
                y = brother;
            }
        }
        heap->root = NULL;
        heap->size--;
    }
    return z;
}

// 斐波那契堆的合并
void merge(FibonacciHeap *heap1, FibonacciHeap *heap2) {
    if (heap1->min == NULL) {
        *heap1 = *heap2;
        free(heap2);
    } else if (heap2->min != NULL) {
        insert(heap1, heap2->min);
        if (heap2->min->key < heap1->min->key) {
            heap1->min = heap2->min;
        }
        free(heap2);
    }
}

// 释放斐波那契堆
void freeFibonacciHeap(FibonacciHeap *heap) {
    Node *x, *y;
    if (heap->min != NULL) {
        x = heap->min;
        while (x != NULL) {
            y = x->right;
            free(x);
            x = y;
        }
    }
    free(heap);
}

int main() {
    int i;
    int intArray[ARRAY_SIZE];
    srand(114514); // 使用114514作为随机数种子

    // 生成整型随机数组
    printf("整型随机数组:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        intArray[i] = rand() % 114514; // 生成0到114514之间的随机整数
        printf("%d ", intArray[i]);
    }
    printf("\n");

    FibonacciHeap *heap = createFibonacciHeap();
    for (i = 0; i < ARRAY_SIZE; i++) {
        insert(heap, createNode(intArray[i]));
    }

    for (i = 0; i < ARRAY_SIZE; i++) {
        Node *minNode = extractMin(heap);
        if (minNode != NULL) {
            intArray[i] = minNode->key;
            free(minNode);
        }
    }

    printf("排序后的整型数组:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");

    freeFibonacciHeap(heap);
    return 0;
}
