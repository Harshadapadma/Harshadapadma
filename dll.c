#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

struct Node* insert(struct Node* head, int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (pos == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
                temp->next->prev = newNode;
            temp->next = newNode;
        } else {
            free(newNode);
        }
    }
    return head;
}

struct Node* delete(struct Node* head, int pos) {
    if (head == NULL)
        return head;
    struct Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    } else {
        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;
        if (temp != NULL) {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}

struct Node* reverse(struct Node* head) {
    struct Node *temp = NULL, *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2->prev = temp;
    return head1;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int choice, data, pos;
    while (1) {
        printf("1. Create\n2. Insert\n3. Delete\n4. Reverse\n5. Concatenate\n6. Display\n7. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            head1 = create(head1, data);
        } else if (choice == 2) {
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            head1 = insert(head1, data, pos);
        } else if (choice == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
            head1 = delete(head1, pos);
        } else if (choice == 4) {
            head1 = reverse(head1);
        } else if (choice == 5) {
            printf("Creating second list\n");
            printf("Enter data for second list: ");
            scanf("%d", &data);
            head2 = create(head2, data);
            head1 = concatenate(head1, head2);
            head2 = NULL;
        } else if (choice == 6) {
            display(head1);
        } else if (choice == 7) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
