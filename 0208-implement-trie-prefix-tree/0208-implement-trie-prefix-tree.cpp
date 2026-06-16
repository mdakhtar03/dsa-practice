class TrieNode{
    public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> children;

    TrieNode(char val){
        data=val;
        isTerminal = false;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }

    void insertWord(TrieNode* root,string word,int i,int size){
        //base case
        if(i == size){
            root->isTerminal = true;
            return;
        }
        char ch = word[i];
        TrieNode* child;
        if(root->children.find(ch) != root->children.end()){
            child = root->children[ch];
        }
        else{
            child = new TrieNode(ch);
            root->children[ch] = child;
        }
        insertWord(child,word,i+1,size);
    }

    bool searchWord(TrieNode* root,string word,int i,int size){
        if(i == size){
            return root->isTerminal;
        }
        TrieNode* child;
        char ch = word[i];
        if(root->children.find(ch) != root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        return searchWord(child,word,i+1,size);
    }
    
    void insert(string word) {
        int i=0, size = word.size();
        insertWord(root,word,i,size);
    }

    bool startsWithWord(TrieNode* root,string word,int i,int size){
        if(i == size){
            return true;
        }
        TrieNode* child;
        char ch = word[i];
        if(root->children.find(ch) != root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        return startsWithWord(child,word,i+1,size);
    }
    bool search(string word) {
        int i=0, size = word.size();
        return searchWord(root,word,i,size);
    }
    
    bool startsWith(string prefix) {
        int i=0, size = prefix.size();
        return startsWithWord(root, prefix,i,size);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */