#include <stdio.h>

int A[100], size, top = -1;

void push() {
    int item;
    if (top == size - 1)
        printf("\nSTACK is full");
    else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &item);
        A[++top] = item;
    }
}

void pop() {
    if (top == -1)
        printf("\nStack is empty");
    else
        printf("\nThe popped element is %d", A[top--]);
}

void display() {
    if (top == -1)
        printf("\nThe STACK is empty");
    else {
        printf("\nThe elements in STACK\n");
        for (int i = 0; i <= top; i++)
            printf("%d\n", A[i]);
    }
}

void status() {
    if (top == -1) {
        printf("Stack is empty");
    } else {
        printf("Stack top element is %d", A[top]);
        if (top == size - 1)
            printf("\nStack is full");
        else
            printf("\nFree space = %.2f%%", (float)(size - top - 1) * 100 / size);
    }
}

void main() {
    int choice;
    printf("\nEnter the size of STACK: ");
    scanf("%d", &size);

    do {
        printf("\n1.PUSH 2.POP 3.DISPLAY 4.STATUS 5.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) push();
        else if (choice == 2) pop();
        else if (choice == 3) display();
        else if (choice == 4) status();
    } while (choice != 5);
}
