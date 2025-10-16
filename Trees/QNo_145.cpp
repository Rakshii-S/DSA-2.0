//Binary Tree Postorder Traversal
//Given the root of a binary tree, return the postorder traversal of its nodes' values.

using namespace std;
#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    void postorderHelper(TreeNode *root, vector<int> &result)
    {
        if(root == nullptr) return;
        postorderHelper(root->left,result);
        postorderHelper(root->right, result);
        result.push_back(root->val);
    }

    vector<int> PostOrderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution s;
    vector<int> result;
    result = s.PostOrderTraversal(n1);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}