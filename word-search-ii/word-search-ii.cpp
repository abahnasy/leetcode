class Trie {
public:
    
    vector<Trie*> kids;
    string word;
    
    
    Trie() {
        kids.resize(26);
        word = "";

    }
    
};

Trie* build_trie(vector<string>& words) {
    Trie *root = new Trie();
    for(auto& w: words) {
        Trie* curr = root;
        for(auto& c: w) {
            if(!curr->kids[c-'a'])
                curr->kids[c-'a'] = new Trie();
            curr = curr->kids[c-'a'];
        }
        curr->word = w;
    }
    
    return root;
}



class Solution {
public:
    
    vector<int> di = {-1,0,1,0};
    vector<int> dj = {0,1,0,-1};
    void bt(
        vector<vector<char>>& board,
        int i, int j,
        Trie* trie,
        vector<string>& res
    ) 
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        char c = board[i][j];
        if (c == '#' || trie->kids[c - 'a'] == nullptr) return;
        Trie *curr_trie = trie->kids[c - 'a'];
        
        if(curr_trie->word != "") {
            res.push_back(curr_trie->word);
            curr_trie->word = "";
        }
        
        board[i][j]='#';
        
        
        
        
        // loop over neighbors
        for(int k = 0; k < 4; ++k) {
            // do the recursive call
            bt(board, i+di[k], j+dj[k], curr_trie, res);
                
            
        }
        
        board[i][j]=c;
        
        
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int M = board.size();
        int N = board[0].size();
        // vector<vector<bool>> visited (M, vector<bool>(N, false));
        vector<string> res;
        
        Trie* root = build_trie(words);
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                bt(board, i, j, root, res);
            }
        }
        
        
        
        return res;
        
        
    }
};