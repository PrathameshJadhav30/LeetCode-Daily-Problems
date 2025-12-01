// Problem Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/description
// Date: 01/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long total = accumulate(arr.begin(), arr.end(), 0LL);

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] <= total / n) break;
            total -= arr[i];
            n--;
        }

        return total / n;
    }
};

int main() {
    Solution s;

    int n = 3;  
    vector<int> arr = {10, 5, 8, 7};

    long long ans = s.maxRunTime(n, arr);
    
    cout << ans << "\n";

    return 0;
}
