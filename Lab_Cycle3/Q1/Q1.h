#include <iostream>

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val);
};

template <typename T>
class BinaryTree {
private:

    void inorderTraversalHelper(TreeNode<T>* node);
    void preorderTraversalHelper(TreeNode<T>* node);
    void postorderTraversalHelper(TreeNode<T>* node);

public:
    TreeNode<T>* root;
    BinaryTree();
    ~BinaryTree();
    
    void destroyTree(TreeNode<T>* node);
    void insert(const T& val);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
};
