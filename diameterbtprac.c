#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int val) {
    int n;
    if (val == -1) {
        return NULL;
    }

    struct node *nd = (struct node *)malloc(sizeof(struct node));

    nd->data = val;

    printf("Enter left child of %d or -1: ", nd->data);
    scanf("%d", &n);
    nd->left = create(n);

    printf("Enter right child of %d or -1: ", nd->data);
    scanf("%d", &n);
    nd->right = create(n);

    return nd;
}

void inorder(struct node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int height(struct node *nod) {
    if (!nod) {
        return 0;
    }

    int lh = height(nod->left);
    int rh = height(nod->right);

    //diam = fmax(1+lh+rh, diam);

    return 1 + fmax(lh, rh);
}

int diameterofbt(struct node *root) {
    if (!root) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    
    int ld = diameterofbt(root->left);
    int rd = diameterofbt(root->right);

    return fmax(1 + lh + rh, fmax(ld, rd));
}

int main() {

    printf("HI");
    int n;
    printf("Enter value of root: ");
    scanf("%d", &n);
    struct node *root = create(n);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int dia = diameterofbt(root);
    printf("Diameter of the binary tree is: %d\n", dia);

    return 0;
}
