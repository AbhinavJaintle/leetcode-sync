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
        if(!root)return 0;
        return 1+max(helper(root->right),helper(root->left));
    }
    void helper2(TreeNode* root, int level, vector<vector<int>>& v, int n){
        if(!root)return;
        v[n-level].push_back(root->val);
        helper2(root->left,level+1,v,n);
        helper2(root->right,level+1,v,n);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = helper(root);
        vector<vector<int>> v(n);
        helper2(root,1,v,n);
        return v;
    }
};