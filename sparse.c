#include <stdio.h>
void createSparseMatrix(int A[10][10], int m, int n) {
    int S[10][3], k = 1;
    S[0][0] = m;
    S[0][1] = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }}}
    S[0][2] = k - 1;
    printf("\nSparse Matrix in Tuple Form:\n");
    for (int i = 0; i <= S[0][2]; i++) {
        printf("%d\t%d\t%d\n", S[i][0], S[i][1], S[i][2]);
    }}
int main() {
    int A[10][10], m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
     } }

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    createSparseMatrix(A, m, n);
    return 0;
}
