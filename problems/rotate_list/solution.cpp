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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* p = head;
        if(p==NULL || p->next==NULL){
            return p;
        }
        while(p->next){
            count += 1;
            p = p->next;
        }
        count += 1;
        p->next = head;
        int temp = 0;
        if(k==0){
            p->next = NULL;
            return head;
        }
        if(k==count){
         while(temp!=k-1){
            head = head->next;
            temp += 1;
         }
        }
        else{
         int target = count - k;
         if(k>count){
             int d = k/count;
             target = count*(d+1)-k;
         }
         temp+=1;
         
         while(temp!=target){
             head = head->next;
             temp+=1;
         }
        }
        ListNode* first = head->next;
        head->next = NULL;
        return first;
    }
};