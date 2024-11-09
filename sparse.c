#include <stdio.h>

void Sparse(int A[10][10], int m, int n) {
    int i, j, k = 1, S[10][10];
    
    // Store the dimensions of the original matrix
    S[0][0] = m;
    S[0][1] = n;
    
    // Convert the matrix to sparse representation
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }
    
    // Store the number of non-zero elements
    S[0][2] = k - 1;
    
    // Display the sparse matrix in tuple form
    printf("\nTuple Form:\n");
    for (i = 0; i <= S[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", S[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[10][10];
    int m, n, i, j;
    
    // Get matrix dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    
    // Get matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    // Call the Sparse function to convert and display the matrix in tuple form
    Sparse(A, m, n);
    
    return 0;
}
