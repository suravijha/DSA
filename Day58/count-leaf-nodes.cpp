// You are given a Binary tree. You have to count and return the number of leaf nodes present in it.

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };

***********************************************************/

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}