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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* temp = new ListNode(head->val);
        head=head->next;
        while(head!=NULL){
            ListNode* t = new ListNode(head->val);
            t->next=temp;
            temp=t;
            head=head->next;
        }
        return temp;
    }
};