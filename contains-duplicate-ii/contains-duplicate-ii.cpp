class Solution {
public:
    int K = -1;
    bool check(int i, vector<int> list) {
        for(int e: list) {
            if (abs(i - e) <= K)
                return true;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        K = k;
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i) {
            cout << "checking " << nums[i] << "\n";
           // if value is empty, add
            if(m.find(nums[i]) != m.end()) {
                bool found = check(i, m[nums[i]]);
                if(found)
                    return true;
                
            } 
            m[nums[i]].push_back(i);
            // else loop over the current indices to check 
        }
        // for(auto itr = m.begin(); itr != m.end(); ++itr) {
        //     cout << itr->first << ": ";
        //     for(auto e: itr->second) {
        //         cout << e << ", ";
        //     }
        //     cout << "\n";
        // }
        return false;
    }
};