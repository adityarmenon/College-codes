#include <stdio.h>

int a[30][30], max[30][30], need[30][30], vis[30], avail[30], seq[30], dupavail[30];
int i, j, k, p, r, ind = 0;

void main() {
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the max allocation matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - a[i][j];

    printf("Enter the available resources: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
        dupavail[i] = avail[i];
    }

    for (i = 0; i < p; i++)
        vis[i] = 0;

    // Banker's Algorithm for Safe Sequence
    for (k = 0; k < p; k++) {
        for (i = 0; i < p; i++) {
            if (vis[i] == 0) {
                int flag = 0;
                for (j = 0; j < r; j++)
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }

                if (flag == 0) {
                    vis[i] = 1;
                    seq[ind++] = i;
                    for (int x = 0; x < r; x++)
                        avail[x] += a[i][x];
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < p; i++)
        if (vis[i] == 0) {
            flag = 0;
            printf("Not a safe sequence\n");
            return;
        }

    printf("Safe sequence: ");
    for (i = 0; i < p - 1; i++)
        printf("P%d -> ", seq[i]);
    printf("P%d\n", seq[i]);

    // Handling resource request
    int req, new[r];
    printf("Enter request process: ");
    scanf("%d", &req);
    printf("Enter the resource request: ");
    for (i = 0; i < r; i++)
        scanf("%d", &new[i]);

    for (j = 0; j < r; j++) {
        if (new[j] > need[req][j]) {
            printf("Error: Request exceeds need.\n");
            return;
        }
    }

    for (i = 0; i < r; i++) {
        a[req][i] += new[i];
        need[req][i] -= new[i];
        avail[i] -= new[i];
    }

    printf("Updated Available Resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avail[i]);
    printf("\n");

    // Checking for new safe sequence
    for (i = 0; i < p; i++)
        vis[i] = 0;
    ind = 0;

    for (k = 0; k < p; k++) {
        for (i = 0; i < p; i++) {
            if (vis[i] == 0) {
                int flag = 0;
                for (j = 0; j < r; j++)
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }

                if (flag == 0) {
                    vis[i] = 1;
                    seq[ind++] = i;
                    for (int x = 0; x < r; x++)
                        avail[x] += a[i][x];
                }
            }
        }
    }

    flag = 1;
    for (i = 0; i < p; i++)
        if (vis[i] == 0) {
            flag = 0;
            printf("Not a safe sequence\n");
            return;
        }

    printf("New Safe sequence: ");
    for (i = 0; i < p - 1; i++)
        printf("P%d -> ", seq[i]);
    printf("P%d\n", seq[i]);
}
