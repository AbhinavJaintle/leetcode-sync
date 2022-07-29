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
    vector<vector<int>> ans;
    stack<TreeNode*> s; 
    queue<TreeNode*> q;
public:
    vector<vector<int>> create(TreeNode* root, int i){
        vector<int> temp;
        while(!q.empty()||!s.empty()){
    
         if(i%2!=0){
            while(!q.empty()){
                if(q.front()!=NULL){
                    temp.push_back(q.front()->val);
                    s.push(q.front()->left);
                    s.push(q.front()->right);
                } 
                q.pop();
            }
            
         }
         else{
            vector<TreeNode*> t;
            while(!s.empty()){
                if(s.top()!=NULL){
                    temp.push_back(s.top()->val);
                    t.push_back(s.top());
                     
                }
                
                s.pop();
            }
            for(int j = t.size()-1; j>-1; j--){
                    q.push(t[j]->left);
                    q.push(t[j]->right);
            }
         }
         if(temp.size()!=0){
             ans.push_back(temp);
         }
         
         i++;
         temp.clear();
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        vector<int> temp = {root->val};
        ans.push_back(temp);
        
        s.push(root->left);
        s.push(root->right);
        create(root, 0); 
        return ans;
    }
};