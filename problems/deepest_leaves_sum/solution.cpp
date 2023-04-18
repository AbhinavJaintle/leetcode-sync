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
    void helper(TreeNode* root, vector<int>&dp, int curr){
        if(!root)return;
        dp[curr]+=root->val;
        curr++;
        helper(root->left, dp, curr);
        helper(root->right, dp, curr);
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<int> dp(1e4+1,0);
        helper(root,dp,0);
        int index=0;
        while(dp[index]!=0)index++;
        return dp[index-1];
    }
};