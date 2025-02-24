#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义矩阵的大小
#define N 1000

// 矩阵乘法函数
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
int A[N][N], B[N][N], result[N][N];
int main() {

    int i, j;

    // 使用随机数填充矩阵
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // 记录开始时间
    clock_t start = clock();

    // 矩阵乘法运算
    multiply_matrices(A, B, result);

    // 记录结束时间
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 输出计算时间
    printf("time: %f s\n", time_taken);

    return 0;
}

