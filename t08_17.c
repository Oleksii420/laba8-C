#include <stdio.h>
#include <stdlib.h>

void rotateBlock90(int **matrix, int startRow, int startCol, int size) {
    for (int layer = 0; layer < size / 2; ++layer) {
        int first = layer;
        int last = size - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[startRow + first][startCol + i];
            matrix[startRow + first][startCol + i] = matrix[startRow + last - offset][startCol + first];
            matrix[startRow + last - offset][startCol + first] = matrix[startRow + last][startCol + last - offset];
            matrix[startRow + last][startCol + last - offset] = matrix[startRow + i][startCol + last];
            matrix[startRow + i][startCol + last] = top;
        }
    }
}

void rotateMatrixBlocks(int **matrix, int n) {
    int size = 2 * n + 1;
    int center = n;

    rotateBlock90(matrix, 0, 0, n);
    rotateBlock90(matrix, 0, n + 1, n);
    rotateBlock90(matrix, n + 1, 0, n);
    rotateBlock90(matrix, n + 1, n + 1, n);
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Введіть n: ");
    scanf("%d", &n);

    int size = 2 * n + 1;
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Введіть елементи матриці (%d x %d):\n", size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }


    rotateMatrixBlocks(matrix, n);

    printf("\nМатриця після повороту блоків:\n");
    printMatrix(matrix, size);

    for (int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
