class BrowserHistory {
public:
    int size=0;
    class ListNode{
        public:
        string val;
        ListNode* next;
        ListNode* prev;
        
        ListNode(string data)
        {
            val=data;
            next=NULL;
            prev=NULL;
        }
    };
     ListNode* head ;
    ListNode* curr ;
    BrowserHistory(string homepage) {
         head = new ListNode(homepage);
         curr = head;
        size++;
    }
    
    void visit(string url) {
        ListNode* node = new ListNode(url);
        curr->next = node;
        node->prev = curr;
        curr=curr->next;
        size++;
    }
    
    string back(int steps) {
        while(curr->prev && steps)
        {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
       while(curr->next && steps)
        {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};