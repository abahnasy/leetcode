//
// Created by Ahmed Bahnasy on 14.06.20.
//

#include "Solution.hpp"
#include <iostream>
int main () {

    vector<int> test {1,2,3,4};
    Solution* sol = new Solution();

    vector<int> res = sol->productExceptSelf(test);

    for (auto x: res) {

        cout << x << " ";
    }
    return 0;
}

