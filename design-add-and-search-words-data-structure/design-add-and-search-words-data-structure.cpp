class TrieNode {
public:
    bool end;
    vector<TrieNode*> kids;
    TrieNode() {
        end = false;
        kids.resize(26);
    }
};

class WordDictionary {
    TrieNode* root = new TrieNode();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* curr = this->root;
        for (auto c: word) {
            if(!curr->kids[c-'a']) curr->kids[c-'a'] = new TrieNode();
            curr = curr->kids[c-'a'];
        }
        curr->end = true;
        
    }
    bool helper_search(TrieNode* curr, string word, int idx) {
        if(idx == word.size()) return curr->end;
        if(word[idx] == '.') {
            for(int i = 0; i < 26; ++i) {
                if(!curr->kids[i]) continue;
                bool res = helper_search(curr->kids[i], word, idx+1);
                if(res) return true;
            }
        } else {
            if(!curr->kids[word[idx]-'a']) return false;
            return helper_search(curr->kids[word[idx]-'a'], word, idx+1);
        }
        return false;
    }
    bool search(string word) {
        TrieNode* curr = this->root;
        return helper_search(curr, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */