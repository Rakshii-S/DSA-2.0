//Maximum Depth of Binary Tree
//Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

using namespace std;
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr) return 1;
        return 1+ min(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(8);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(8);
    TreeNode *n9 = new TreeNode(9);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    n4->right = n9;

    Solution s;
    int depth = s.maxDepth(n1);
    cout<<"Maximum depth: "<<depth;
}