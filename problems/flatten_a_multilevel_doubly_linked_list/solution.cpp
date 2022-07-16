/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        int num = 0;
        Node* p = new Node;
        Node* t = new Node;
        t = head;
        while(t){
            if(t->child!=NULL){
                num+=1;
            }
            t = t->next;
        }
        if(num==0){
            return head;
        }
        else{
            p = head;
            Node* first = new Node;
            first = p;
            while(p){
                if(p->child!=NULL){
                    Node* temp = new Node;
                    Node* temp2 = new Node;
                    temp = p;
                    temp2 = temp->next;
                    p->next = p->child;
                    p->next->prev = p;
                    p->child = NULL;
                    Node* d = new Node;
                    d = p->next;
                    while(d->next){
                        d = d->next;
                    }
                    d->next = temp2;
                    if(temp2!=NULL){
                        temp2->prev = d;
                    }
                    
                }
                p = p->next;
            }
            Node* flatten(Node* first);
        }
        return head;
    }
};