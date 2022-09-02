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
    int c = 0;
public:
    void ver(TreeNode* root, int count,queue<pair<int,int>>& q){
        if(root==NULL){
            c=max(c,count);
            return;
        }
        q.push({count,root->val});
        ver(root->left,count+1,q);
        ver(root->right,count+1,q);
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<int,int>> q;
        ver(root,0,q);
        vector<double> ans(c,0);
        vector<double> cu(c,0);
        while(!q.empty()){
            ans[q.front().first]+=q.front().second;
            cu[q.front().first]++;
            q.pop();
        }
        for(int i = 0; i<c;i++){
            ans[i]/=cu[i];
        }
        return ans;
    }
};