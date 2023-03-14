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
    int helper(TreeNode* root, string curr){
        if(!root)return stoi(curr);
        int start1=0;
        int start2=0;
        curr+=to_string(root->val);
        start1=helper(root->left,curr);
        start2=helper(root->right,curr);
        if(!root->left&&!root->right)start2=0;
        else if(!root->left)start1=0;
        else if(!root->right)start2=0;
        return start1+start2;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,"");
    }
};