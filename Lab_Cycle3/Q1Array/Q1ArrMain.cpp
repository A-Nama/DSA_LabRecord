#include "Q1Arr.cpp"

int main() {
    BinaryTree tree(10); // Create a binary tree with a maximum size of 10

    // Insert elements into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    // Perform traversals
    cout << "Pre-order traversal: ";
    tree.preOrder();
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrder();
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder();
    cout << endl;

    return 0;
}