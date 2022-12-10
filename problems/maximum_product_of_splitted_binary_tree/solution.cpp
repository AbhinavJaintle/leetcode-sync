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
 
class Solution {
public:
    int maxProduct(TreeNode* root) {
        
    }
};
"
*/
static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum=0,result=0;
        void getTotalTreeSum(TreeNode* root)    //Get total sum of the tree.
            {
                    if(!root)
                                return;
                                        totalTreeSum+=root->val;
                                                getTotalTreeSum(root->left);
                                                        getTotalTreeSum(root->right);
                                                            }
                                                                int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
                                                                    {
                                                                           if(!root)
                                                                                       return 0;
                                                                                              int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right); //Get the sumresultsumresult/*
                                                                                              /*
sumresultsumresult
*/
/*"
resulresulresulresulresulresulresuresulresulresulresulresulresulresuresulresult*/
/*
result/result*resultresult
result
"
resultrerresultreresultrerres
resultrerres
*/

result=max({result,(totalTreeSum-sumUnderLeft)*sumUnderLeft,(totalTreeSum-sumUnderRight)*sumUnderRight});    //Get the max product after making left or right subtrees as seprarate tree.
       return sumUnderLeft+sumUnderRight+root->val;
           }
               int maxProduct(TreeNode* root) 
                   {
                           getTotalTreeSum(root);
                                   SumUnder(root);
                                           return result%MOD;
                                               }
                                               };                         /* SumUnder(root);
                                           return result%MOD;
                                               }
                          SumUnder(root);
                                           return result%MOD;
                                               }
                                               };*/