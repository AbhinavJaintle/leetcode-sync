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
    unordered_map<int,int> m = {};
    void helper(TreeNode* root, int level){
        if(!root)return;
        m[level]+=root->val;
        helper(root->left,level+1);
        helper(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        helper(root,1);
        int maxi = root->val;
        int curr=1;
        for(auto&i:m){
            if(maxi<i.second){
                maxi=i.second;
                curr=i.first;
            }    
        }
        return curr;
    }
};