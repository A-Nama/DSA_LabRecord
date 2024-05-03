#include "Q1Arr.h"

BinaryTree::BinaryTree(int maxSize) {
    size = maxSize;
    tree = new int[size];
    for (int i = 0; i < size; ++i) {
        tree[i] = -1; // Initialize all elements as empty (-1)
    }
}

BinaryTree::~BinaryTree() {
    delete[] tree;
}

void BinaryTree::insert(int value) {
    // Find the first empty spot in the array for insertion
    for (int i = 0; i < size; ++i) {
        if (tree[i] == -1) {
            tree[i] = value;
            break;
        }
    }
}

void BinaryTree::preOrderTraversal(int index) {
    if (index >= size || tree[index] == -1) {
        return;
    }
    std::cout << tree[index] << " "; // Process current node
    preOrderTraversal(2 * index + 1); // Traverse left subtree
    preOrderTraversal(2 * index + 2); // Traverse right subtree
}

void BinaryTree::inOrderTraversal(int index) {
    if (index >= size || tree[index] == -1) {
        return;
    }
    inOrderTraversal(2 * index + 1); // Traverse left subtree
    std::cout << tree[index] << " "; // Process current node
    inOrderTraversal(2 * index + 2); // Traverse right subtree
}

void BinaryTree::postOrderTraversal(int index) {
    if (index >= size || tree[index] == -1) {
        return;
    }
    postOrderTraversal(2 * index + 1); // Traverse left subtree
    postOrderTraversal(2 * index + 2); // Traverse right subtree
    std::cout << tree[index] << " ";  // Process current node
}

void BinaryTree::preOrder() {
    preOrderTraversal(0); // Start traversal from the root (index 0)
}

void BinaryTree::inOrder() {
    inOrderTraversal(0); // Start traversal from the root (index 0)
}

void BinaryTree::postOrder() {
    postOrderTraversal(0); // Start traversal from the root (index 0)
}
