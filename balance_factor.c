#include<stdio.h>
typedef struct node{
    int info;
    struct node *left,*right;
    int b_factor;
}NODE;

NODE* create(NODE *bnode,int x){
    if(bnode==NULL){
        bnode=(NODE*) malloc(sizeof(NODE));
        bnode->info=x;
        bnode->left=bnode->right=NULL;
    }else if(x>bnode->info)
        bnode->right=create(bnode->right,x);
    else if(x<bnode->info)
        bnode->left=create(bnode->left,x);
    else{
        printf("Duplicate node\n"); exit(0);
    }
    return(bnode);
}

void inorder(NODE *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%5d %d\n",ptr->info,ptr->b_factor);
        inorder(ptr->right);
    }
}

void postorder(NODE *ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%5d %d\n",ptr->info,ptr->b_factor);
    }
}

void preorder(NODE *ptr){
    if(ptr!=NULL){
        printf("%5d %d\n",ptr->info,ptr->b_factor);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int height(NODE *ptr){
    if(ptr == NULL){
        return 0;
    }else{
        int lheight = height(ptr->left);
        int rheight = height(ptr->right);
        return 1 + (lheight>rheight ? lheight : rheight);
    }
}

void node_factor(NODE* ptr){
    if(ptr == NULL){
        int i = 0;
    }else{
        ptr->b_factor = height(ptr->left) - height(ptr->right);
        node_factor(ptr->left);
        node_factor(ptr->right);
    }
}


void main(){
    int n,x,ch,i;
    NODE *root;
    root=NULL;
    while(1){
        printf("********************Output********************\n\n");
        printf(" 	Menu 	\n");
        printf(" 1. Insert\n 2. All traversals\n 3. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter node (do not enter duplicate nodes):\n");
                scanf("%d",&x);
                root=create(root,x);
                break;
            case 2:
                printf("\nInorder traversal:\n");
                node_factor(root);
                inorder(root);
                printf("\nPreorder traversal:\n");
                preorder(root);
                printf("\nPostorder traversal:\n");
                postorder(root);
                printf("\n\n*********************************************");
                break;
            case 3:
                exit(0);
        }
    }
}