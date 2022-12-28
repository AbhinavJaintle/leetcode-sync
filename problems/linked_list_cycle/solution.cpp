/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||head->next==NULL) return false;
        ListNode* start = head;
        head=head->next->next;
        if(head==start){
            return true;
        }
        while(head){
            if(head==start){
                return true;
            }
            start=start->next;
            head=head->next!=NULL?head->next->next:NULL;
        }
        return false;
    }
};