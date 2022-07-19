class Solution {
public:
    void reorderList(ListNode* head) {
        // handle edge cases
        
        // no nodes
        if(head == nullptr)
            return;
        
        // one node only
        if(head->next == nullptr)
            return;
        
        // only 2 nodes
        if(head->next->next == nullptr)
            return;
        
        ListNode *headPointer, *tailPointer;
        headPointer = tailPointer = head;
        while(tailPointer->next->next != nullptr){
            tailPointer = tailPointer->next;
        }
        
        // now tailPointer is pointing to a node before tail
        ListNode* tailNode = tailPointer->next;
        tailPointer->next = nullptr; // cut the connection
        ListNode* nextOfHead = headPointer->next;
        headPointer->next = tailNode;
        tailNode->next = nextOfHead;
        
        // call rec function
        reorderList(nextOfHead);
        
        return;
    }
};