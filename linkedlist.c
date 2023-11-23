#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = *head;
    Node* previous = NULL;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < position) {
        printf("Position exceeds the length of the list\n");
        free(newNode);
        return;
    }

    previous->next = newNode;
    newNode->next = current;
}

// Function to delete a node with a given value from the linked list
void deleteNode(Node** head, int key) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found\n", key);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

// Function to search for a value in the linked list
Node* search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL; // Set the head to NULL after freeing all nodes
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Linked List after inserting at the beginning: ");
    printList(head);

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Linked List after inserting at the end: ");
    printList(head);

    insertAtPosition(&head, 10, 2);

    printf("Linked List after inserting at position 2: ");
    printList(head);

    deleteNode(&head, 4);

    printf("Linked List after deleting node with value 4: ");
    printList(head);

    Node* searchResult = search(head, 2);
    if (searchResult != NULL) {
        printf("Node with value 2 found\n");
    } else {
        printf("Node with value 2 not found\n");
    }

    freeList(&head);

    return 0;
}
