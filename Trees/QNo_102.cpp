//Binary Tree Level Order Traversal
//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

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
    vector<vector<int>> LevelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> currLevel;
            for(int i=0;i<size;i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            result.push_back(currLevel);
        }
        return result;
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(8);
    TreeNode *n5 = new TreeNode(5);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution s;
    vector<vector<int>> result;
    result = s.LevelOrderTraversal(n1);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}