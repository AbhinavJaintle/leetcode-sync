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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p = new ListNode();
        stack<int> s;
        p = head;
        int n = 0;
        if(left==right){
            return head;
        }
        while(p->next){
            if(n>=left-1&&n<=right-1){
                s.push(p->val);
            }
            n++;
            p = p->next;
        }
        if(n>=left-1&&n<=right-1){
            s.push(p->val);
        }
        ListNode* ans = new ListNode();
        ListNode* curr = new ListNode();
        if(left!=1){
            curr->val = head->val;
            
        }
        else{
            curr->val = s.top();
            s.pop();
            
        }
        head = head->next;

        ans = curr;
        
        for(int i = 1; i<n+1; i++){
            ListNode* temp = new ListNode();
            
            if(i>=left-1&&i<=right-1){
                temp->val = s.top();
                s.pop();
            }
            else{
                temp->val = head->val;
            }
            curr->next = temp;
            curr = temp;
            head = head->next;
        }
        return ans;
    }
};