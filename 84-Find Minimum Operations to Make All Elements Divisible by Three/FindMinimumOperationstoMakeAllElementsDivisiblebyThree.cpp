//Problem Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description
// Date: 22/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int minimumOperations(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [&](int sum, int x){
            return sum + (x % 3 != 0);
        });
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6, 9};  

    int result = Solution::minimumOperations(nums);

    cout << "Minimum Operations = " << result << endl;

    return 0;
}
