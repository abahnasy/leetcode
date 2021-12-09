class Solution {
public:
    tuple<int, bool, int> read_log(string s) {
        vector<string> vs;
        string tmp;
        stringstream ss(s);
        while(getline(ss, tmp, ':')) {
            vs.push_back(tmp);
        }
        
        int id = stoi(vs[0]);
        bool is_start = (vs[1] == "start")?true: false;
        int time = stoi(vs[2]);
        
        return make_tuple(id, is_start, time);
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> s; // keep IDs      
        vector<int> res (n,0);
        auto [prev_id, is_start, prev_time] = read_log(logs[0]);
        s.push(prev_id);
        // process input
        for(int i = 1; i < logs.size(); ++i) {
            auto [id, is_start, time] = read_log(logs[i]);
            if(is_start) {
                if(s.size()>=1)
                    res[s.top()] += time - prev_time;
                prev_time = time;
                s.push(id);
            } else {
                res[s.top()] += time - prev_time+1;
                s.pop();
                prev_time = time+1;
            }
        }
        
        // assert (s.size() == 0);
        
        
            
        
        return res;
    }
};