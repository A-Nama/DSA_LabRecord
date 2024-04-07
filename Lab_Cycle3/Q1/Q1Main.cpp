#include "Q1.cpp"

int main() {
    BinaryTree<int> binaryTree;

    int n;
    cout << "Enter the number of nodes to insert: " << endl;
    cin >> n;

    cout << "Enter values: " << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        binaryTree.insert(value);
    }

    cout << "Inorder Traversal: ";
    binaryTree.inorderTraversal();

    cout << "Preorder Traversal: ";
    binaryTree.preorderTraversal();

    cout << "Postorder Traversal: ";
    binaryTree.postorderTraversal();

    return 0;
}
