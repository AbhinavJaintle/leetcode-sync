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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* p = new ListNode;
        p = head;
        while(p){
            count+=1;
            p = p->next;
        }
        if(count==1){
            head=NULL;
            return head;
        }
        p = head;
        int target = count - n;
        int temp = 0;
        if(target!=0){
         while(temp!=target-1){
            p=p->next;
            temp+=1;
         }
        }
        else{
            head = head->next;
            return head;
        }
        p->next = p->next->next;
        return head;
    }
    
};