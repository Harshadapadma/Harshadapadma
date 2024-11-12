#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            root = insert(root, data);
        } else if (choice == 2) {
            inorder(root);
            printf("\n");
        } else if (choice == 3) {
            preorder(root);
            printf("\n");
        } else if (choice == 4) {
            postorder(root);
            printf("\n");
        } else if (choice == 5) {
            printf("Enter key to search: ");
            scanf("%d", &data);
            struct Node* result = search(root, data);
            if (result != NULL) printf("Found\n");
            else printf("Not found\n");
        } else if (choice == 6) {
            printf("Enter key to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
        } else if (choice == 7) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
