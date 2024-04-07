#include "Q1.h"
using namespace std;

template <typename T>
TreeNode<T>::TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    if (root == nullptr)
        return;
    
    destroyTree(root);
}

template <typename T>
void BinaryTree<T>::destroyTree(TreeNode<T>* node) {
    if (node == nullptr)
        return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}


template <typename T>
void BinaryTree<T>::insert(const T& val) {
    TreeNode<T>* newNode = new TreeNode<T>(val);
    if (root == nullptr) {
        root = newNode;
        return;
    }

    TreeNode<T>* current = root;
    TreeNode<T>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

template <typename T>
void BinaryTree<T>::inorderTraversalHelper(TreeNode<T>* node) {
    if (node == nullptr)
        return;
    inorderTraversalHelper(node->left);
    cout << node->data << " ";
    inorderTraversalHelper(node->right);
}

template <typename T>
void BinaryTree<T>::preorderTraversalHelper(TreeNode<T>* node) {
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorderTraversalHelper(node->left);
    preorderTraversalHelper(node->right);
}

template <typename T>
void BinaryTree<T>::postorderTraversalHelper(TreeNode<T>* node) {
    if (node == nullptr)
        return;
    postorderTraversalHelper(node->left);
    postorderTraversalHelper(node->right);
    cout << node->data << " ";
}

template <typename T>
void BinaryTree<T>::inorderTraversal() {
    inorderTraversalHelper(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::preorderTraversal() {
    preorderTraversalHelper(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::postorderTraversal() {
    postorderTraversalHelper(root);
    cout << endl;
}
