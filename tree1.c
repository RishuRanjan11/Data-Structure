#include <stdio.h>
#include <stdlib.h> // Correcting the header for malloc
typedef struct tree
{
    int data;
    struct tree *left, *right;
} tree;

void inOrderTraversal(tree *root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(tree *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(tree *root) {
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main(int argc, char const *argv[])
{
    tree *root;
    tree *temp;
    root = (tree *)malloc(sizeof(tree));
    tree *curr = root;
    printf("Enter the root value: ");
    scanf("%d", &(curr->data));
    curr->left = curr->right = NULL;

    int option;
    do
    {
        printf("Do you want to insert more child? 1 or 0: ");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("Enter the data of child: ");
            temp = (tree *)malloc(sizeof(tree));
            scanf("%d", &(temp->data));
            if((temp->data) > (root->data))
            {
                (root->data)=(temp->data);
            }
            else if ((temp->data) < (root->data))
            {
                curr->left = temp;
            }
            else
                curr->right = temp;
            curr = temp;
            curr->left = curr->right = NULL; // Setting left and right child to NULL for the newly added node
        }
    } while (option);

    printf("\nIn-order Traversal: ");
    inOrderTraversal(root);
    printf("\nPre-order Traversal: ");
    preOrderTraversal(root);
    printf("\nPost-order Traversal: ");
    postOrderTraversal(root);

    return 0;
}
