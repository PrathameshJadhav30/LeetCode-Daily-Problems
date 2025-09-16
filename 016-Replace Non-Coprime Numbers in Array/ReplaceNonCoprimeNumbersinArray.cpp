//Problem Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description
//Date: 16/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; // stack
        for (int num : nums) {
            st.push_back(num);
            // keep merging while top 2 are non-coprime
            while (st.size() > 1) {
                int a = st.back();
                int b = st[st.size() - 2];
                int g = gcd(a, b);
                if (g == 1) break; // coprime, stop merging
                st.pop_back();
                st.back() = lcm(a, b); // replace with LCM
            }
        }
        return st;
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};

int main() {
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};

    Solution sol;
    vector<int> result = sol.replaceNonCoprimes(nums);

    cout << "Final modified array: ";
    for (int x : result){
      cout << x << " ";
    } 
    cout << "\n";

    return 0;
}
