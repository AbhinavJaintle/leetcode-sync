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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* start = head;
        while(start){
            v.push_back(start->val);
            start=start->next;
        }
        int l = v.size()-k;
        int i = 0;
        start=head;
        int flag = 0;
        while(flag!=2){
            if(i==k-1){
                start->val=v[l];
                flag++;
            }
            if(i==l){
                start->val=v[k-1];
                flag++;
            }
            i++;
            start=start->next;
        }
        return head;
    }
};