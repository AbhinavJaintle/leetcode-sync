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
    int maxi = 0;
public:
    void helper(TreeNode* root, char flag, int curr){
        if(root==NULL){ 
            maxi=max(maxi,curr);
            return;
        }
        if(flag=='r'){ 
            helper(root->left,'l',curr+1);
            helper(root->right,'r',0);
        }
        else{ 
            helper(root->right,'r',curr+1);
            helper(root->left,'l',0);
        }

    }
    int longestZigZag(TreeNode* root) {
        helper(root->left,'l',0);
        helper(root->right,'r',0);
        return maxi;
    }
};