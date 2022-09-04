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
    vector<pair<int,pair<int,int>>> in;
public:
    void inorder(TreeNode* root, int n, int m){
        if(root==NULL){
            return;
        }
        in.push_back({n,{root->val,m}});
        inorder(root->left,n-1,m+1);
        inorder(root->right,n+1,m+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        in.clear();
        inorder(root,0,0);
        sort(in.begin(),in.end());
        vector<vector<pair<int,int>>> ans;
        int prev = in[0].first;
        vector<pair<int,int>> temp;
        for(auto&i:in){
            if(i.first==prev){
                temp.push_back({i.second.second,i.second.first});
            }
            else{
                prev = i.first;
                ans.push_back(temp);
                temp.clear();
                temp.push_back({i.second.second,i.second.first});
            }
        }
        if(temp.size()!=0){
            ans.push_back(temp);
        }
        vector<vector<int>> fin;
        for(auto&i: ans){
            sort(i.begin(),i.end());
            vector<int> temp;
            for(auto&j: i){
                temp.push_back(j.second);
            }
            fin.push_back(temp);
        }
        return fin;
    }
};