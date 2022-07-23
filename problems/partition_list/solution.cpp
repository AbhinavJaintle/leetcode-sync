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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1head = new ListNode();
        ListNode* l2head = new ListNode();
        ListNode* l1last = new ListNode();
        ListNode* l2last = new ListNode();
        ListNode* p = head;
        if(head==NULL){
            return head;
        }
        int head1 = 0;
        int head2 = 0;
        while(p!=NULL){
          if(p->val<x){
           
            if(head1==0){
                l1head->val = p->val;
                l1last = l1head;
                head1=1;
            }
            else{
                ListNode* temp = new ListNode();
                temp->val = p->val;
                l1last->next = temp;
                l1last = temp;
            }
              
          }
          else{
           
            if(head2==0){
                l2head->val = p->val;
                l2last = l2head;
                head2=1;
            }
            else{
                ListNode* temp = new ListNode();
                temp->val = p->val;
                l2last->next = temp;
                l2last = temp;
            }
              
          }
          p = p->next;
        }
        if(head1==0){
            return l2head;
        }
        if(head2==0){
            return l1head;
        }
        l1last->next = l2head;
        return l1head;
        
    }
};