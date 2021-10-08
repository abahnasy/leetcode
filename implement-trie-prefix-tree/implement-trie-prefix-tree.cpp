class Trie {
public:
    
    vector<Trie*> kids;
    bool end;
    
    Trie() {
        end = false;
        kids.resize(26);

    }
    
    void insert(string word) {
        Trie* curr = this;
        for(auto c: word) {
            if(!curr->kids[c-'a']) {
                curr->kids[c-'a'] = new Trie();
            } 
            curr = curr->kids[c-'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (auto c: word) {
            if(!curr->kids[c-'a']) return false;
            curr = curr->kids[c-'a'];
        }
        if(curr->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(auto c: prefix) {
            if(!curr->kids[c-'a']) return false;
            curr = curr->kids[c-'a'];
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