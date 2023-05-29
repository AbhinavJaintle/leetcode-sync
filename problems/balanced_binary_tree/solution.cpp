/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root){
        if(root==NULL)return 0;
        int a = helper(root->left);
        int b = helper(root->right);
        if(a==-1||b==-1||abs(a-b)>1)return -1;
        return 1+max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        return (helper(root)!=-1);
    }
};