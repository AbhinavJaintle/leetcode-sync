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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* root = head;
        while(root!=NULL){
            count++;
            root=root->next;
        }
        root = head;
        if(count==1){
            return NULL;
        }
        count/= 2;
        count-=1;
        
        while(count){
            head=head->next;
            count--;
        }
        head->next=head->next->next;
        return root;
    }
};