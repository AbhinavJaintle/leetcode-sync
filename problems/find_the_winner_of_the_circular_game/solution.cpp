class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1){
            return n;
        }
        ListNode* root = new ListNode(1);
        ListNode* head = root;
        for(int i = 2; i<n+1; i++){
            ListNode* temp = new ListNode(i);
            root->next = temp;
            root=temp;
        }
        root->next = head;
        int count = n-1;
        while(count!=0){
            int round = k-2;
            while(round!=0){
                head = head->next;
                round--;
            }
            head->next = head->next->next;
            head=head->next;
            count--;
        }
        return head->val;
    }
};