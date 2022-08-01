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
    vector<string> ans;
    
    bool paths(TreeNode* root, string s){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return true;
        }
        s+=to_string(root->val)+"->";
        paths(root->left, s);
        paths(root->right, s);
        return false;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string s = "";
        paths(root, s);
        return ans;
    }
};