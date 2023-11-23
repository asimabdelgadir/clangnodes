#include <stdio.h>
#include <stdlib.h>

// Structure defining a node in the binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node with given data
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
Node *insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the binary tree
Node *search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the minimum value node in a binary tree
Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary tree
Node *deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the tree (Left-Root-Right)
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    insert(root, 6);
    insert(root, 14);
    insert(root, 5);
    insert(root, 8);

    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    int searchData = 6;
    Node *searchResult = search(root, searchData);
    if (searchResult != NULL) {
        printf("%d found in the tree.\n", searchData);
    } else {
        printf("%d not found in the tree.\n", searchData);
    }

    int deleteData = 14;
    root = deleteNode(root, deleteData);
    printf("Inorder traversal after deleting %d: ", deleteData);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
