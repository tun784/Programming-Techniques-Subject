#include <stdio.h>
#include <limits.h>
void inputArray(int arr[], int n) {
    printf("Enter elements of the array\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element at index A[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
int findMinEven(int A[], int n) {
    int minEven = INT_MAX; // Initialize minEven to a very large value
    for (int i = 0; i < n; i++)
        if (A[i] % 2 == 0 && A[i] < minEven)
            minEven = A[i];
    return minEven;
}
void inputMatrix(int matrix[][100], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
}
void printDiagonals(int matrix[][100], int size) {
    printf("Elements on the diagonals parallel to the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");

    printf("Elements on the diagonals parallel to the anti-diagonal:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][size - 1 - i]);
    }
    printf("\n");
}
int sumOfMinInRows(int matrix[][100], int size) {
    int totalMinSum = 0;
    for (int i = 0; i < size; i++) {
        int minForRow = matrix[i][0];  // Initialize min to the first element of the row
        for (int j = 1; j < size; j++) {
            if (matrix[i][j] < minForRow) {
                minForRow = matrix[i][j];
            }
        }
        totalMinSum += minForRow;
    }
    return totalMinSum;
}
int findMaxSumColumn(int matrix[][100], int size) {
    int maxSum = 0;  // Initialize the maximum sum to 0
    int maxSumColumn = 0;  // Initialize the column with maximum sum to 0

    for (int j = 0; j < size; j++) {
        int sum = 0;  // Initialize sum for the current column
        for (int i = 0; i < size; i++) {
            sum += matrix[i][j];  // Accumulate the sum for the current column
        }

        if (sum > maxSum) {
            maxSum = sum;
            maxSumColumn = j;
        }
    }

    return maxSumColumn;
}
int main(){
    int option;
    do {
        printf("Vui long nhap yeu cau: ");
        scanf("%d",&option);
        switch (option) {
        case 1:
            int choice;
            do {
            printf("Vui long nhap lua chon: ");
                scanf("%d",&choice);
                switch (choice) {
                    case 1:{
                        int n;

                            printf("Enter the size of the array: ");
                            scanf("%d", &n);

                            int arr[100];

                            inputArray(arr, n);

                            printf("Entered array:\n");
                            for (int i = 0; i < n; i++) {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                    }break;
                    case 2:{
                            int A[] = {5, 3, 7, 1, 9, 11};
                            int n = sizeof(A) / sizeof(A[0]);
                            int minEven = findMinEven(A, n);

                            if (minEven != INT_MAX) {
                                printf("The minimum even number in the array is: %d\n", minEven);
                            } else {
                                printf("No even numbers found in the array.\n");
                            }
                    } break;
                    default:
                        break;
                }
            }while (choice != 0);
        case 2: {
                int choice;
                scanf("%d",&choice);
                switch (choice) {
                case 1: {
                        int rows, cols;
                        
                        printf("Enter the number of rows: ");
                        scanf("%d", &rows);

                        printf("Enter the number of columns: ");
                        scanf("%d", &cols);

                        int matrix[100][100];

                        inputMatrix(matrix, rows, cols);

                        printf("Matrix entered by the user:\n");
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < cols; j++)
                                printf("%d\t", matrix[i][j]);
                            printf("\n");
                        }
                } break;
                case 2: {
                        int size;

                        printf("Enter the size of the square matrix: ");
                        scanf("%d", &size);

                        int matrix[100][100];

                        printf("Enter elements of the matrix:\n");
                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) {
                                printf("Enter element at position [%d][%d]: ", i, j);
                                scanf("%d", &matrix[i][j]);
                            }
                        }

                        printf("Entered matrix\n");
                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) 
                                printf("%d\t", matrix[i][j]);
                            printf("\n");
                        }

                        printDiagonals(matrix, size);
                } break;
                    case 3:{
                        int size;

                            printf("Enter the size of the square matrix: ");
                            scanf("%d", &size);

                            int matrix[100][100];

                            printf("Enter elements of the matrix:\n");
                            for (int i = 0; i < size; i++) {
                                for (int j = 0; j < size; j++) {
                                    printf("Enter element at position [%d][%d]: ", i, j);
                                    scanf("%d", &matrix[i][j]);
                                }
                            }

                            printf("Entered matrix:\n");
                            for (int i = 0; i < size; i++) {
                                for (int j = 0; j < size; j++) {
                                    printf("%d\t", matrix[i][j]);
                                }
                                printf("\n");
                            }

                            int totalMinSum = sumOfMinInRows(matrix, size);
                            printf("Total sum of minimum elements in each row: %d\n", totalMinSum);
                    }break;
                    case 4:{
                        int size;

                        printf("Enter the size of the square matrix: ");
                        scanf("%d", &size);

                        int matrix[100][100];

                        printf("Enter elements of the matrix:\n");
                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) {
                                printf("Enter element at position [%d][%d]: ", i, j);
                                scanf("%d", &matrix[i][j]);
                            }
                        }

                        printf("Entered matrix:\n");
                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) {
                                printf("%d\t", matrix[i][j]);
                            }
                            printf("\n");
                        }

                        int maxSumColumn = findMaxSumColumn(matrix, size);
                        printf("Column with the maximum sum of elements: %d\n", maxSumColumn);
                    }break;
                default:
                    break;
                }
            }
        break;
        default:
            break;
        }
    }while (option != 0);

    return 0;
}
