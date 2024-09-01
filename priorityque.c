#include <stdio.h>

int s, f, r;
int item, priority;  // Global variables to store the item and priority

struct PQ {
    int item, priority;
} A[20];

void display() {
    int i;
    if (f == -1)
        printf("Queue is EMPTY\n");
    else {
        for (i = f; i <= r; i++)
            printf("%d\t", A[i].item);
        printf("\n");
    }
}

void enqueue() {  // No parameters
    int i, loc;
    if (f == 0 && r == s - 1)
        printf("Queue is FULL\n");
    else if (f == -1) {
        f = 0;
        r = 0;
        A[r].item = item;       // Use global variable item
        A[r].priority = priority; // Use global variable priority
    } else {
        if (r == s - 1) {
            for (i = f; i <= r; i++)
                A[i - 1] = A[i];
            f--;
            r--;
        }
        for (i = r; i >= f; i--) {
            if (A[i].priority < priority) {
                break;
            }
        }
        loc = i + 1;
        for (i = r; i >= loc; i--) {
            A[i + 1] = A[i];
        }
        A[loc].item = item;         // Use global variable item
        A[loc].priority = priority; // Use global variable priority
        r++;
    }
}

void dequeue() {  // No parameters
    if (f == -1)
        printf("Queue is empty\n");
    else if (f == r) {
        printf("Deleted item is %d\n", A[f].item);
        f = -1;
        r = -1;
    } else {
        printf("Deleted item is %d\n", A[f].item);
        f++;
    }
}

void main() {
    int opt;
    f = -1;
    r = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &s);

    do {
        printf("\nEnter the option\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the item and priority: ");
                scanf("%d%d", &item, &priority);
                enqueue();  // Call without arguments
                break;
            case 2:
                dequeue();  // Call without arguments
                break;
            case 3:
                display();  // Call without arguments
                break;
            case 4:
                break;
            default:
                printf("Enter a valid option\n");
        }
    } while (opt != 4);
}
