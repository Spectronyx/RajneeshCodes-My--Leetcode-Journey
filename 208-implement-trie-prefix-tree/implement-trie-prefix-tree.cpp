struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
};

class Trie {
private: Node* root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        // ek dummy node banao jo root ko refer kare
        Node *node = root;

        // poore word string ko traverse karo
        for(int i = 0;i < word.length();++i){
            //check karo node par word i exist karta hai ya nahi
            // agar nahi to waha put kar do;
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;

        for(int i = 0;i< word.size();++i){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
        
    }
    
    bool startsWith(string word) {
        Node *node = root;

        for(int i = 0;i < word.size();++i){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
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