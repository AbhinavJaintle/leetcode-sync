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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = new ListNode;
        ListNode* q = new ListNode;
        ListNode* head = new ListNode;
        ListNode* temp = new ListNode;
        p = list1;
        q = list2;
        if(p==NULL&&q==NULL){
            return NULL;
        }
        else if(p==NULL){
            return q;
        }
        else if(q==NULL){
            return p;
        }
        if(p->val<=q->val){
                head = p;
                temp = head;
                p = p->next;
            }
        else{
                head = q; 
                temp = head;
                q = q->next;
            }
            
        while(p!=NULL && q!=NULL){
            if(p->val<=q->val){
                temp->next = p;
                temp = p;
                p = p->next;
            }
            else{
                temp->next = q;
                temp = q;
                q = q->next;
            }
        };
        if(p==NULL){
            while(q!=NULL){
                temp->next = q;
                temp = q;
                q = q->next;
            }
        }
        else{
            while(p!=NULL){
                temp->next = p;
                temp = p;
                p = p->next;
            }
        }
        return head;
    }
};