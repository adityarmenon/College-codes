#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*link;
  
};
void display(struct node* head){
    struct node* ptr = head;
    if(head == NULL){
        printf("It is empty");
    }
    else{
        while(ptr != NULL){
            printf("%d", ptr->data);
            ptr = ptr->link;
        }
    }
}

void insertatfront(struct node**head, int data){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link =*head;
    *head = newnode;
}
void insertatend(struct node** head, int data){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode -> data= data;
    newnode ->link =NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
       struct node *ptr = *head;
       while(ptr->link!=NULL){
        ptr = ptr -> link;
        ptr -> link = newnode;
       }
    }

    }
    void insertatposition(struct node**head, int data, int position, int key){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode -> data = data;
        struct node* ptr = *head;
        while(ptr->data != key){
            ptr = ptr->link;
        }
        newnode -> link = ptr -> link;
        ptr -> link = newnode;
    }
    void deleteatfront(struct node**head){
        if(*head==NULL){
            printf("List is empty");
        }
        else{
            struct node *temp =* head;
            *head = (*head)-> link;
            free(temp);
        }
    }
        
    
    void deleteatend(struct node**head){
        {
            if(*head==NULL){
            printf("List is empty");
        }
        else if((*head)->link==NULL){
            struct node* temp = *head;
            *head = NULL;
            free(temp);
        }
        else{
            struct node*prev = *head;
            struct node* curr = (*head)->link;
            while(curr -> link!=NULL){
                prev = curr;
                curr = curr -> link;

            }
            prev ->link = NULL;
            free(curr);
        }
        }

    }
    void sear(struct node**head, int key){
        if(*head ==NULL){
            printf("List is empty");
        }
        else{
            struct node*ptr = *head;
            while (ptr->data != key && ptr->link != NULL){
                ptr = ptr -> link;
            }
            if(ptr -> data == key){
                printf("Element found");
            }
            else{
                printf("Element not found");
            }

        }
    }
void main(){
    struct node*ptr;
    ptr = (struct node*)malloc(sizeof( struct node ));


    struct node* head = NULL;
    int data, position, key, ch;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at front\n");
        printf("5. Delete at end\n");
        printf("6. Search\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertatfront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertatend(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position after which to insert: ");
                scanf("%d", &key);
                insertatposition(&head, data, position, key);
                break;
            case 4:
                deleteatfront(&head);
                break;
            case 5:
                deleteatend(&head);
                break;
            case 6:
                printf("Enter key to search: ");
                scanf("%d", &key);
                sear(&head, key);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

