#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *link;
};

// Function to display the linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Function to insert a node at the front
void insert_front(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;
}

// Function to insert a node at the end
void insert_end(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *ptr = *head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new_node;
    }
}

// Function to delete a node from the front
void delete_front(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->link;
    free(temp);
}

// Function to delete a node from the end
void delete_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->link == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *prev = NULL, *curr = *head;
    while (curr->link != NULL) {
        prev = curr;
        curr = curr->link;
    }
    free(curr);
    prev->link = NULL;
}

int main() {
    struct node *head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete from front\n");
        printf("4. Delete from end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insert_front(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 3:
                delete_front(&head);
                break;
            case 4:
                delete_end(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, try again\n");
        }
    }

    return 0;
}