//Problem Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description
// Date: 07/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long left = *min_element(stations.begin(), stations.end());
        long right = accumulate(stations.begin(), stations.end(), 0L) + k + 1;

        while (left < right) {
            const long mid = (left + right) / 2;
            if (check(stations, r, k, mid))
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1;
    }

private:
    bool check(vector<int> stations, int r, int additionalStations, long minPower) {
        const int n = stations.size();
        long power = 0;
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stations[i];

        // sliding window initial power
        power = prefix[min(n, r + 1)] - prefix[0];

        vector<long> added(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i + r < n)
                power = prefix[min(n, i + r + 1)] - prefix[max(0, i - r)];

            if (power < minPower) {
                const long requiredPower = minPower - power;
                if (requiredPower > additionalStations)
                    return false;
                added[min(n - 1, i + r)] += requiredPower;
                additionalStations -= requiredPower;
                prefix[min(n, i + r + 1)] += requiredPower;
                for (int j = i + r + 1; j <= n; ++j)
                    prefix[j] += requiredPower;  // maintain updated prefix
                power += requiredPower;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> stations = {1, 2, 4, 5, 0};
    int r = 1;  // range of effect
    int k = 2;  // additional stations we can add

    cout << "Stations: ";
    for (int s : stations) cout << s << " ";
    cout << "\nRange (r): " << r << "\nAdditional stations (k): " << k << endl;

    long long result = sol.maxPower(stations, r, k);
    cout << "Maximum minimum power possible: " << result << endl;

    return 0;
}
