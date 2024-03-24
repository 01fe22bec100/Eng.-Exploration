#include <stdio.h>
#define MAX_SIZE 10
void matrixAddition(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void matrixSubtraction(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void matrixMultiplication(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrixTranspose(int mat[][MAX_SIZE], int transposed[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = mat[i][j];
        }
    }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Addition
    if (rows1 == rows2 && cols1 == cols2) {
        printf("Addition:\n");
        matrixAddition(mat1, mat2, result, rows1, cols1);
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Matrix addition is not possible due to mismatched dimensions.\n");
    }

    // Subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        printf("Subtraction:\n");
        matrixSubtraction(mat1, mat2, result, rows1, cols1);
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Matrix subtraction is not possible due to mismatched dimensions.\n");
    }

    // Multiplication
    if (cols1 == rows2) {
        printf("Multiplication:\n");
        matrixMultiplication(mat1, mat2, result, rows1, cols1, cols2);
        displayMatrix(result, rows1, cols2);
    } else {
        printf("Matrix multiplication is not possible due to mismatched dimensions.\n");
    }

    printf("Transpose of the first matrix:\n");
    int transposed[MAX_SIZE][MAX_SIZE];
    matrixTranspose(mat1, transposed, rows1, cols1);
    displayMatrix(transposed, cols1, rows1);

    return 0;
}

