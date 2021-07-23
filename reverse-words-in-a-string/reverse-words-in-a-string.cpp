class Solution {
public:
    string reverseWords(string s) {

        stringstream ss (s);
        vector<string> vs;
        
        string str = "";
        
        while (ss >> str) {
                vs.push_back(str);
        }
        
        
        string res;
        int c = 0;
        for(auto itr = vs.rbegin(); itr != vs.rend(); ++itr) {
            res.append(*itr);
            ++c;
            if(c < vs.size())
                res.append(" ");
        }


    return res;
    }
};