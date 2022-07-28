class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size() && q.front() != NULL){
            vector<int> tmp;
            while(q.front() != NULL){
                tmp.push_back(q.front()->val);
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(tmp);
            q.pop();
            q.push(NULL);
        }
        return ans;
    }
};