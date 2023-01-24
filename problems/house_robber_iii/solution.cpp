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
    int dfs(TreeNode* root, bool flag, map<pair<TreeNode*,bool>,int>& m){
        if(!root)return 0;
        int num1 = 0;
        int num2 = 0;
        if(m[{root,flag}])return m[{root,flag}];
        if(flag){
            num1=root->val+dfs(root->left,false,m)+dfs(root->right,false,m);
        }
        num2=dfs(root->left,true,m)+dfs(root->right,true,m);
        return m[{root,flag}]=max(num1,num2);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int> m;
        return dfs(root,true,m);
    }
};