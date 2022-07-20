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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2=l2->next;
        }
        stack<int> ans;
        int carry = 0;
        while(!st1.empty()&&!st2.empty()){
            int x = st1.top();
            int y = st2.top();
            st1.pop();
            st2.pop();
            int sum = x+y+carry;
            
            ans.push(sum%10);
            
            if(floor(log10(sum))>0){
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        if(!st1.empty()){
            while(!st1.empty()){
              int sum = st1.top()+carry;
              st1.pop();
            
              ans.push(sum%10);
            
              if(floor(log10(sum))>0){
                 carry = 1;
              }
              else{
                  carry = 0;
              } 
            }
        }
        else if(!st2.empty()){
            while(!st2.empty()){
              int sum = st2.top()+carry;
              st2.pop();
            
              ans.push(sum%10);
            
              if(floor(log10(sum))>0){
                 carry = 1;
              }
              else{
                  carry = 0;
              } 
            }
        }
        if(carry!=0){
            ans.push(carry);
        }
        ListNode* p = new ListNode();
        p->val = ans.top();
        ans.pop();
        ListNode* head = p;
        while(!ans.empty()){
            ListNode* temp = new ListNode(ans.top());
            ans.pop();
            p->next = temp;
            p = temp;
        }
        return head;
    }
};