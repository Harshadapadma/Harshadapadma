#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createnode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
        return createnode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to delete a node from the BST
struct Node* deletenode(struct Node* root, int data) {
    if (root == NULL) 
        return root;
    if (data < root->data)
        root->left = deletenode(root->left, data);
    else if (data > root->data)
        root->right = deletenode(root->right, data);
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
        struct Node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

// Function to find minimum node in the BST
struct Node* findMin(struct Node* root) {
    if (root == NULL) 
        return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find maximum node in the BST
struct Node* findMax(struct Node* root) {
    if (root == NULL) 
        return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to find the successor of a given node
struct Node* successor(struct Node* root, struct Node* node) {
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            if (root->right != NULL) {
                successor = findMin(root->right);
            }
            break;
        }
    }
    return successor;
}

// Function to find the predecessor of a given node
struct Node* predecessor(struct Node* root, struct Node* node) {
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            root = root->left;
        } else if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            if (root->left != NULL) {
                predecessor = findMax(root->left);
            }
            break;
        }
    }
    return predecessor;
}

// Inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Input number of elements to insert into the BST
    printf("How many elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];

    // Input elements and insert into the BST
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        root = insert(root, arr[i]);
    }

    // Inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Finding a node for which to find the successor and predecessor
    printf("Enter the node to find successor and predecessor: ");
    int nodeValue;
    scanf("%d", &nodeValue);
    struct Node* node = findMin(root); // Temporary node to hold the input node

    // Searching for the node in the BST
    struct Node* searchNode = NULL;
    struct Node* current = root;
    while (current != NULL) {
        if (current->data == nodeValue) {
            searchNode = current;
            break;
        } else if (nodeValue < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node was found
    if (searchNode != NULL) {
        struct Node* succ = successor(root, searchNode);
        struct Node* pred = predecessor(root, searchNode);
        printf("Successor of %d: %d\n", nodeValue, succ ? succ->data : -1);
        printf("Predecessor of %d: %d\n", nodeValue, pred ? pred->data : -1);
    } else {
        printf("Node with value %d not found in the BST.\n", nodeValue);
    }

    // Deleting a node (example with a specified value)
    printf("Deleting node %d\n", 20);
    root = deletenode(root, 20);
    
    // Inorder traversal after deletion
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
