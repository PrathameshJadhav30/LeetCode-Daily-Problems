//Problem Link: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description
// Date: 15/11/2025
#include <bits/stdc++.h>
using namespace std;

uint16_t p0[40001];
int front, back;

class Solution {
public:
    static int numberOfSubstrings(string& s) {
        const int n = s.size();
        const int Zmax = (sqrt(1.0 + 4 * n) - 1) / 2;

        front = back = 0; // reset queue

        // Collect all positions of zeroes in s
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                p0[back++] = i;
        }

        p0[back++] = n; // sentinel

        int ans = 0;

        for (int l = 0; l < n; l++) {
            while (p0[front] < l) front++;

            int prev = l;

            for (int p = front; p < back; p++) {
                int cnt0 = p - front;
                int r = p0[p];

                if (cnt0 > Zmax) break;

                int minLen = max(prev - l + 1, cnt0 * (cnt0 + 1));

                ans += max(0, (r - l) - minLen + 1);

                prev = r;
            }
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main() {

    string s = "1101001";

    cout << "Input string: " << s << "\n";
    cout << "Output: " << Solution::numberOfSubstrings(s) << "\n";

    return 0;
}
