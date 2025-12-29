// Problem Link: https://leetcode.com/problems/pyramid-transition-matrix/description
// Date: 29/12/2025
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
using namespace std;

// type alias as requested
using u8 = unsigned char;

u8 pattern[36];                 // 6 * 6 combinations (A–G)
const int N = 117649;           // 7^6
bitset<N> BAD[7];               // memo per row length

class Solution {
public:
    // Encode string into base-7 number
    static inline unsigned encode(const string& s) {
        unsigned ans = 0;
        for (char c : s) {
            ans = ans * 7 + (c - 'A');
        }
        return ans;
    }

    // Build allowed transition patterns
    static inline void addPattern(const vector<string>& allowed) {
        for (const auto& s : allowed) {
            u8 idx = (s[0] - 'A') * 6 + (s[1] - 'A');
            pattern[idx] |= 1 << (s[2] - 'A');
        }
    }

    // DFS to build pyramid
    static bool dfs(const string& cur, string& next, int i, int sz) {
        if (i == sz - 1) {
            if (sz == 2) return true;

            unsigned idx = encode(next);
            if (BAD[sz - 1][idx]) return false;

            string up(sz - 1, 'G');
            if (!dfs(next, up, 0, sz - 1)) {
                BAD[sz - 1][idx] = 1;
                return false;
            }
            return true;
        }

        u8 key = (cur[i] - 'A') * 6 + (cur[i + 1] - 'A');
        unsigned mask = pattern[key];

        while (mask) {
            unsigned bit = mask & -mask;
            mask -= bit;

            int c = __builtin_ctz(bit);
            next[i] = 'A' + c;

            if (dfs(cur, next, i + 1, sz))
                return true;
        }
        return false;
    }

    static bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(pattern, 0, sizeof(pattern));
        for (int i = 0; i <= 6; i++) BAD[i].reset();

        addPattern(allowed);

        string next(bottom.size() - 1, 'G');
        return dfs(bottom, next, 0, bottom.size());
    }
};

int main() {
    
    string bottom = "BCD";
    vector<string> allowed = {
        "BCC", "CDE", "CEA", "FFF"
    };

    bool result = Solution::pyramidTransition(bottom, allowed);

   
    cout << "Bottom: " << bottom << endl;
    cout << "Pyramid Possible: " << (result ? "YES" : "NO") << endl;

    return 0;
}
