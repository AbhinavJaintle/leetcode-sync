struct Node{
    Node* list[26];
    bool flag = false;
    
    bool contains(char ch){
        return (list[ch-'a']!=NULL);
    }
    void put(char ch){
        list[ch-'a'] = new Node();
        return;
    }
    Node* getNext(char ch){
        return list[ch-'a'];
    }
    
};

class Trie {
    Node* node;
public:
    Trie() {
        node = new Node();
    }
    
    void insert(string word) {
        Node* root = node;
        for(int i = 0; i<word.length(); i++){
            if(!root->contains(word[i])){
                root->put(word[i]);
            }
            root = root->getNext(word[i]);
        }
        root->flag = true;
        return;
    }
    
    bool search(string word) {
        Node* root = node;
        for(int i = 0; i<word.length(); i++){
            if(!root->contains(word[i])){
                return false;
            }
            root = root->getNext(word[i]);
        }
        return (root->flag==true);
    }
    
    bool startsWith(string prefix) {
        Node* root = node;
        for(int i = 0; i<prefix.length(); i++){
            if(!root->contains(prefix[i])){
                return false;
            }
            root = root->getNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */