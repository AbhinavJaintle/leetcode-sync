/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        int n = 0;
        while(head){
            v.push_back(head->val);
            head=head->next;
            n++;
        }
        int maxi = 0;
        for(int i = 0; i<=n/2-1; i++){
            maxi=max(maxi,v[i]+v[n-i-1]);
        }
        return maxi;
    }
};