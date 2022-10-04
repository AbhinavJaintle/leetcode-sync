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
    bool path(TreeNode* root, int targetSum, int curr){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            if(curr+root->val==targetSum){
                return true;
            }
            return false;
        }
        bool p1 = false;
        bool p2 = false;
        if(root->left!=NULL){
            p1= path(root->left,targetSum,curr+root->val);
        }
        if(root->right!=NULL){
            p2= path(root->right,targetSum,curr+root->val);
        }
        return p1||p2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return path(root,targetSum,0);
    }
};