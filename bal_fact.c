#include<stdio.h>

typedef struct node{
    int data;
    int b_factor;
    struct node *left;
    struct node *right
}NODE;

NODE* createNode(NODE *root, int x){

    if(root == NULL){
        root = (NODE*)malloc(sizeof(NODE));
        root->data = x;
        root->b_factor = 0;
        root->left = NULL;
        root->right = NULL;
    }
    else if (x<root->data)
    {
        root->left = createNode(root->left, x);
    }
    else if(x>root->data){
        root->right = createNode(root->right, x);
    }
    return root;
    
}

void inorder(NODE *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%5d   %d\n", ptr->data, ptr->b_factor);
        inorder(ptr->right);
    }
}

int height(NODE *ptr){
    if(ptr == NULL){
        return 0;
    }
    else{
        int lheight = height(ptr->left);
        int rheight = height(ptr->right);

        return 1+ (lheight>rheight?lheight:rheight);
    }
}

void bal_factor(NODE* ptr){
    if(ptr == NULL){
        return 0;
    }
    else{
        ptr->b_factor = height(ptr->left) - height(ptr->right);
        bal_factor(ptr->left);
        bal_factor(ptr->right);
    }
}

int main(){
    int n,x,ch,i;
    NODE *root;
    root = NULL;

    while(1){
        printf("********************Output********************\n\n");
        printf(" 	Menu 	\n");
        printf(" 1. Insert\n 2. All traversals\n 3. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter node (do not enter duplicate nodes):\n");
            scanf("%d",&x);
            root=createNode(root,x);
            break;
        
        case 2:
            
            printf("\nInorder traversal:\n");
            bal_factor(root);
            inorder(root);
            break;

        case 3:
            exit(0);
        }


    }
}