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
    int minDiffInBST(TreeNode* root) {
        if(!root){
            return INT_MAX;
        }
        int mini = INT_MAX;
        if(root->left){
            int curr = root->left->val;
            TreeNode* prev = root->left;
            while(prev->right){
                prev=prev->right;
            }
            mini=min(mini,root->val-prev->val);
        }
        if(root->right){
            int curr = root->right->val;
            TreeNode* prev = root->right;
            while(prev->left){
                prev=prev->left;
            }
            mini=min(mini,prev->val-root->val);
        }
        return min({mini,minDiffInBST(root->left), minDiffInBST(root->right)});
    }
};