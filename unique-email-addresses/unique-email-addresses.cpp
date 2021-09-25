class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // read string by string
        // skip dots
        // when reach + sign run till @
        set<string> res;
        for(auto s: emails) {
            string temp;
            for(int i =0; i < s.size(); ++i) {
                if(s[i] == '.') continue;
                if(s[i] == '+') {
                    while(s[i] != '@')
                        ++i;
                    temp += s.substr(i, s.size());
                    break;
                }
                if(s[i] == '@') {
                    temp += s.substr(i, s.size());
                    break;
                }
                temp += s[i];
            }
            cout << "inserted string is: " << temp << endl;
            res.insert(temp);
        }
        
        return res.size();
    }
};