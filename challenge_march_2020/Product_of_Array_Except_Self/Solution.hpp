//
// Created by Ahmed Bahnasy on 14.06.20.
//

#ifndef LEETCODE_SOLUTION_HPP
#define LEETCODE_SOLUTION_HPP

#include <vector>
using namespace std;

class Solution {
public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> left(nums.size(), 0);
//         vector<int> right(nums.size(), 0);
//         left[0] = 1;
//         for (int i = 1; i < nums.size(); ++i) {
//             left[i] = left[i-1] * nums[i-1];
//         }

//         right[nums.size()-1] = 1;
//         for (int i = nums.size()-2; i >= 0; --i) {
//             right[i] = right[i+1] * nums[i+1];
//         }
//         right[nums.size() -1] = 1;

//         vector<int> res(nums.size(), 0);
//         for (int i = 0; i < nums.size(); ++i) {
//             res[i] = right[i] * left[i];
//         }


//         return res;
//     }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int l = 1;
        int r = 1;
        for (int i = 0; i < n; ++i) {
            res[i] *= l;
            l *= nums[i];

            res[n-1-i] *= r;
            r *= nums[n-1-i];
        }

        return res;
    }

};




#endif //LEETCODE_SOLUTION_HPP
