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
    int diff = 0;
public:
    void anc(TreeNode* root, int mini, int maxi){
        if(root==NULL){
            return;
        }
        int d1 = abs(root->val-mini);
        int d2 = abs(root->val-maxi);
        diff = max(max(d1,d2),diff);
        if(root->val<mini){
            mini = root->val;
        }
        if(root->val>maxi){
            maxi = root->val;
        }
        anc(root->left,mini,maxi);
        anc(root->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        anc(root->left,root->val,root->val);
        anc(root->right,root->val,root->val);
        return diff;
    }
};