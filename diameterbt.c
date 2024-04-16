#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int val){
    int n;
    if (val == -1){
        return NULL;
    }
    struct node* nd;
   
    nd = (struct node*) malloc(sizeof(struct node));

    nd->data = val;

    printf("enter left child of %d or -1: ",nd->data);
    scanf("%d",&n);
    nd->left=create(n);

    printf("enter right child of %d or -1: ",nd->data);
    scanf("%d",&n);
    nd->right=create(n);

    return nd;

}

void inorder(struct node* root){
    if(root){
        inorder(root ->left);
        printf("%d", root->data);
        inorder(root->right);
    }
       
}

int height(struct node* nod , int dia){
    if(!nod){
        return 0 ;
    }


    int lh = height(nod->left , dia);
    int rh = height(nod->right, dia);

    dia = fmax(dia, lh + rh);
    
    return 1 + fmax(lh, rh);

}

int diameterofbt(struct node* root){
    int dia;
    height(root, dia);

    return dia;


}

int main(){

    printf("HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
    int n;
    printf("enter value of root:");
    scanf("%d",&n);
    struct node* root=create(n);
    inorder(root);
    printf("\n");
    int dia = diameterofbt(root);
    printf("Diameter of the binary tree is: %d\n", dia);

}