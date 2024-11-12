#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* min(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* max(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* s(struct node* root, struct node* node) {
    struct node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            if (root->right != NULL) {
                successor = min(root->right);
            }
            break;
        }
    }
    return successor;
}

struct node* p(struct node* root, struct node* node) {
    struct node* predecessor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            root = root->left;
        } else if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            if (root->left != NULL) {
                predecessor = max(root->left);
            }
            break;
        }
    }
    return predecessor;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createnode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    struct node* t = root->left->right;
    struct node* successor = s(root, t);
    struct node* predecessor = p(root, t);
    
    printf("Inorder Successor of %d: ", t->data);
    if (successor != NULL) {
        printf("%d\n", successor->data);
    } else {
        printf("null\n");
    }
    
    printf("Inorder Predecessor of %d: ", t->data);
    if (predecessor != NULL) {
        printf("%d\n", predecessor->data);
    } else {
        printf("NULL\n");
    }

    return 0;
}
