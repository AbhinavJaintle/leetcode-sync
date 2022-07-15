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
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode;
        vector< int > arr;
        int temp = -101;
        p = head;
        if(p==NULL){
            return p;
        }
        while(p->next){
            if(p->val == p->next->val||p->val==temp){
                temp = p->val;
            }
            else{
                arr.push_back(p->val);
            }
            p=p->next;
        }
        if(p->val != temp){
            arr.push_back(p->val);
        }
        if(arr.size()==0){
            return head = NULL;
        }
        int i;
        ListNode* t = new ListNode;
        ListNode* last = new ListNode;
        ListNode* first = new ListNode;
        first->val=arr[0];
        first->next=NULL;
        last=first;
        int n = arr.size();
        for(i=1;i<n;i++){
                ListNode* t = new ListNode;
                t->val=arr[i];
                t->next=NULL;
                last->next=t;
                last=t;
        }
        return first;
        
    }
};