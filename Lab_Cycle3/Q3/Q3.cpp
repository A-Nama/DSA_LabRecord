#include "Q1.cpp"
#include <queue>

template <typename T>
void levelOrderTraversal(TreeNode<T>* root) {
    if (root == nullptr)
        return;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<T>* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

