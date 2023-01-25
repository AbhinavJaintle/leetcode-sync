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
    vector<int> v={};
    int index=0;
public:
    int helper(TreeNode* root, vector<int>& voyage){
        if(index==voyage.size())return 0;
        if(root->val!=voyage[index])return -1;
        index++;
        if((root->left&&(root->left->val==voyage[index]))||!root->left){
            if(root->left&&(helper(root->left,voyage)==-1))return -1;
            if(root->right&&(helper(root->right,voyage)==-1))return -1;
        }
        else{
            v.push_back(root->val);
            if(root->right&&(helper(root->right,voyage)==-1))return -1;
            if(root->left&&(helper(root->left,voyage)==-1))return -1;
        }
        return 0;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(helper(root,voyage)==-1)return {-1};
        return v;
    }
};