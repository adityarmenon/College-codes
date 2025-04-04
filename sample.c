#include <stdio.h>

int main() {
    int n, bt[100], rt[100], wt[100], tat[100];
    int quantum, time = 0, i;
    int done, total_wt = 0, total_tat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for p %d: ", i);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while (!done);

    // Turnaround Time Calculation
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nTotal Waiting Time: %d", total_wt);
    printf("\nTotal Turnaround Time: %d", total_tat);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
