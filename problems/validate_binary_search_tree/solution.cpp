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
    vector<int> ans = {};
public:
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int curr;
        if(!ans.empty()){
            curr = ans[0];
        }
        
        for(int i = 1; i<ans.size();i++){
            int temp  = ans[i];
            if(temp<=curr){
                return false;
            }
            else{
                curr = ans[i];
            }
        }
        return true;
    }
};