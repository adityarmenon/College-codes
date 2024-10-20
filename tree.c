#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root =NULL, *new = NULL, *loc= NULL, *ploc = NULL, *par = NULL, *ptr = NULL;
int ch, key, item, flag = 0;
int main() {
    void build(struct node* ptr);
    void inorder(struct node* ptr);
    void search(struct node* par, struct node* ptr);
    void insert(int item);
    void deleteNode();

    root = (struct node*)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;

    printf("\nBuilding the tree...\n");
    build(root);  

    printf("\nInorder traversal of the tree:\n");
    inorder(root);  

    printf("\nEnter key to search: ");
    scanf("%d", &key);
    search(NULL, root);  
    if (loc == NULL)
        printf("\nKey not found.\n");
    else
        printf("\nKey found.\n");

    if (loc != NULL) {
        insert(loc);  
        printf("\nInorder traversal after insertion:\n");
        inorder(root); 
    }

    deleteNode();  
    printf("\nInorder traversal after deletion:\n");
    inorder(root);  

    return 0;
}
struct node* createnode(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
        return newnode;
    }

void build(struct node* ptr) {
    printf("\nEnter item: ");
    scanf("%d", &ptr->data);

    printf("\nWant to create left child for %d? If yes, enter 0: ", ptr->data);
    scanf("%d", &ch);
    if (ch == 0) {
        new = (struct node*)malloc(sizeof(struct node));
        ptr->left = new;
        new->left = NULL;
        new->right = NULL;
        build(new);
    }

    printf("\nWant to create right child for %d? If yes, enter 0: ", ptr->data);
    scanf("%d", &ch);
    if (ch == 0) {
        new = (struct node*)malloc(sizeof(struct node));
        ptr->right = new;
        new->left = NULL;
        new->right = NULL;
        build(new);
    }
}
void insert(int item){
    if(root==NULL){
        struct node* newnode = createnode();
        newnode -> data= item;
        newnode -> left = NULL;
        newnode -> right = NULL;
        newnode = root;
    }
    else{
        ptr = root;
        while ( ptr !=NULL && flag == 0)
        {
            if(item = ptr ->data){
                flag == 1;
                printf("Item is present");
                break;
            }
            if(ptr -> data >item){
                par = ptr;
                ptr = ptr -> left;
                            }
            else{
                par = ptr;
                ptr = ptr -> right;
        }
        if(ptr == NULL){
            struct node* newnode = createnode();
            
        }

    }
}