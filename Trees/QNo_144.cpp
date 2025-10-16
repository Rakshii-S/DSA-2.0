//Binary Tree Preorder Traversal
//Given the root of a binary tree, return the preorder traversal of its nodes' values.

using namespace std;
#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution{
    public:
    void preorderHelper(TreeNode* root, vector<int> &result)
    {
        if(root == nullptr) return;
        result.push_back(root->val);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }

    vector<int> PreorderTraversal(TreeNode* root)
    {
        vector<int> result;
        preorderHelper(root,result);
        return result;
    }
};

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;

    Solution s;
    vector<int> result;
    result = s.PreorderTraversal(n1);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}