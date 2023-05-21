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
    int helper(TreeNode* root, unordered_map<int,int>& m){
        if(!root)return 0;
        int val = root->val+helper(root->left,m)+helper(root->right,m);
        m[val]++;
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
        helper(root,m);
        int maxi = 0;
        for(auto&i:m){
            maxi=max(maxi,i.second);
        }
        vector<int> ans;
        for(auto&i:m){
            if(i.second==maxi)ans.push_back(i.first);
        }
        return ans;
    }
};