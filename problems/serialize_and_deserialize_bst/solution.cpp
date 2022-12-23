/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string temp = "";
    int index = 0;
    string des = "";
    // Encodes a tree to a single string.
    void serhelp(TreeNode* root){
        if(root==NULL){
            temp+="NULL";
            return;
        }
        temp+=to_string(root->val)+"#";
        serhelp(root->left);
        serhelp(root->right);
    }
    string serialize(TreeNode* root) {
        serhelp(root);
        return temp;
    }
    TreeNode* deshelp(){
        if(index>=des.length()||des[index]=='N'){
            index+=4;
            return NULL;
        }
        string t;
        while(des[index]!='#'){
            t.push_back(des[index]);
            index++;
        }
        index++;
        int v = stoi(t);
        TreeNode* root = new TreeNode(v);
        root->left=deshelp();
        root->right=deshelp();
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        des=data;
        return deshelp();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;