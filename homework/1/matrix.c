#include <stdio.h>
#include <stdlib.h>

// 轉置矩陣
void transpose(double *mat, double *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j * rows + i] = mat[i * cols + j];
        }
    }
}

// 矩陣相加
void add(double *mat1, double *mat2, double *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = mat1[i * cols + j] + mat2[i * cols + j];
        }
    }
}

// 矩陣相乘
void multiply(double *mat1, double *mat2, double *result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i * cols2 + j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i * cols2 + j] += mat1[i * cols1 + k] * mat2[k * cols2 + j];
            }
        }
    }
}

// 印出矩陣
void dump(double *mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", mat[i * cols + j]);
        }
        printf("\n");
    }
}

// 測試函式庫
int main() {
    int rows1 = 2, cols1 = 3;
    int rows2 = 3, cols2 = 2;

    double mat1[] = {1, 2, 3, 4, 5, 6};
    double mat2[] = {7, 8, 9, 10, 11, 12};

    double result_add[rows1 * cols1];
    double result_multiply[rows1 * cols2];
    double result_transpose[cols1 * rows1];

    // 相加
    add(mat1, mat2, result_add, rows1, cols1);
    printf("Matrix Addition:\n");
    dump(result_add, rows1, cols1);

    // 相乘
    multiply(mat1, mat2, result_multiply, rows1, cols1, cols2);
    printf("\nMatrix Multiplication:\n");
    dump(result_multiply, rows1, cols2);

    // 轉置
    transpose(mat1, result_transpose, rows1, cols1);
    printf("\nMatrix Transpose:\n");
    dump(result_transpose, cols1, rows1);

    return 0;
}
