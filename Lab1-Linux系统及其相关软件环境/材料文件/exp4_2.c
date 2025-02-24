#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义矩阵的大小
#define N 1000  // 这个N值可以调大，增加内存使用量

// 矩阵初始化，随机生成稀疏矩阵
void initialize_sparse_matrix(int matrix[N][N], int sparsity) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            // 根据稀疏度sparsity，矩阵中大部分为零
            matrix[i][j] = (rand() % 100 < sparsity) ? 0 : rand() % 100;
        }
    }
}

// 矩阵乘法
void multiply_matrices(int A[N][N], int B[N][N], int result[N][N]) {
    int i, j, k;

    // 初始化结果矩阵
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result[i][j] = 0;
        }
    }

    // 矩阵乘法计算
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // 声明三个全矩阵
    int (*A)[N] = malloc(sizeof(int[N][N]));
    int (*B)[N] = malloc(sizeof(int[N][N]));
    int (*result)[N] = malloc(sizeof(int[N][N]));

    if (A == NULL || B == NULL || result == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    // 初始化随机数种子
    srand(time(NULL));

    // 初始化稀疏矩阵，稀疏度设为90%，即90%的元素为0
    initialize_sparse_matrix(A, 90);
    initialize_sparse_matrix(B, 90);

    // 记录开始时间
    clock_t start = clock();

    // 矩阵乘法运算
    multiply_matrices(A, B, result);

    // 记录结束时间
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 输出计算时间
    printf("time:%f s\n", time_taken);

    // 释放内存
    free(A);
    free(B);
    free(result);

    return 0;
}

