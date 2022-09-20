struct Node{
    Node* links[26];
    bool flag = false;
};

class WordDictionary {
private:
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(char ch : word){
            if(!node->links[ch - 'a']){
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }
    
    bool search(const string &word, int i = 0, Node* node = nullptr) {
        if(node == nullptr) node = root;
        if(i >= word.size()) return node->flag;
        for(; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(node->links[ch - 'a'] == nullptr){
                    return false;
                }
                return search(word, i+1, node->links[ch - 'a']);
            } else {
                bool ans = false;
                for(auto n : node->links){
                    if(!n) continue;
                    ans |= search(word, i+1, n);
                }
                return ans;
            }
        }
        return false;
    }
};