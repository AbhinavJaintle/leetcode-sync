/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        queue<vector<Node*>> q;
        q.push({root});
        q.push({});
        vector<vector<Node*>> ans;
        vector<Node*> temp;
        while(!q.empty()){
            vector<Node*> u = q.front();
            q.pop();
            if(u.size()==0){
                ans.push_back(temp);
                
                temp.clear();
                continue;
            }
            for(auto&i:u){
              for(auto&j:i->children){
                temp.push_back(j);
              }
            }
            q.push(temp);
            q.push({});
        }
        vector<vector<int>> p;
        p.push_back({root->val});
        for(auto&i:ans){
            vector<int> temp;
            for(auto&j:i){
                temp.push_back(j->val);
                
            }
            if(temp.size()!=0)
                p.push_back(temp);
        }
        return p;
    }
};