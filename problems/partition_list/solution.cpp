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
        
        ListNode* l1Head = new ListNode;
        ListNode* l2Head = new ListNode;
        ListNode* l1last = new ListNode;
        ListNode* l2last = new ListNode;
        ListNode* p = new ListNode;
        int head1 = 0;
        int head2 = 0;
        p = head;
        cout<<endl;
        if(head==NULL){
            return head;
        }
        while(p!=NULL){
            if(p->val<x){
                if(head1==0){
                    l1Head->val = p->val;
                    l1Head->next = NULL;
                    l1last = l1Head;
                    head1=1;
                }
                else{
                    ListNode* l1 = new ListNode;
                    l1->val = p->val;
                    l1->next = NULL;
                    l1last->next = l1;
                    l1last = l1;
                }
            }
            else{
                
                if(head2==0){
                    l2Head->val = p->val;
                    l2Head->next = NULL;
                    l2last = l2Head;
                    head2 = 1;
                }
                else{
                    ListNode* l2 = new ListNode;
                    l2->val = p->val;
                    l2->next = NULL;
                    l2last->next = l2;
                    l2last = l2;
                }     
            }
            p = p->next;
        }
        
        if(head1==0){
            return l2Head;
        }
        if(head2==0){
            l1last = NULL;
            return l1Head;
        }
        l1last->next = l2Head;
        return l1Head;   
        
}
};