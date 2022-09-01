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
    int count;
public:
    void good(TreeNode* root, int curr){
        if(root==NULL){
            return;
        }
        if(root->val>=curr){
            curr=root->val;
            count++;
        }
        good(root->left,curr);
        good(root->right,curr);
                
    }
    int goodNodes(TreeNode* root) {
        count=0;
        good(root,-1*(1e+5));
        return count;
    }
};