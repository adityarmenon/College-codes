#include <stdio.h>

struct poly {
    int coeff;
    int expo;
} poly1[10], poly2[10], p3[10];

int inputPoly(struct poly p[]) {
    int n, i, c, e;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Term %d - Enter the coefficient: ", i + 1);
        scanf("%d", &c);
        printf("Enter the exponent: ");
        scanf("%d", &e);
        p[i].coeff = c;
        p[i].expo = e;
    }
    return n;
}

void showPoly(struct poly p[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" + ");
        printf("%d(x^%d)", p[i].coeff, p[i].expo);
    }
}

int addPolys(struct poly p1[], struct poly p2[], int n1, int n2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k++] = (struct poly){p1[i].coeff + p2[j].coeff, p1[i++].expo};
            j++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k++] = p1[i++];
        } else {
            p3[k++] = p2[j++];
        }
    }
    while (i < n1) p3[k++] = p1[i++];
    while (j < n2) p3[k++] = p2[j++];
    return k;
}

int main() {
    int n1 = inputPoly(poly1);
    int n2 = inputPoly(poly2);
    int n3 = addPolys(poly1, poly2, n1, n2, p3);
    printf("\nResult: ");
    showPoly(p3, n3);
    return 0;
}
