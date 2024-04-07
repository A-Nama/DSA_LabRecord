#include "Q3.cpp"

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
    cout << endl;

    cout << "Preorder Traversal: ";
    binaryTree.preorderTraversal();
    cout << endl;

    cout << "Postorder Traversal: ";
    binaryTree.postorderTraversal();
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(binaryTree.root);
    cout << endl;

    return 0;
}
