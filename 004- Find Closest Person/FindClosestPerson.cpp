//Problem Link: https://leetcode.com/problems/find-closest-person/description
//Date: 04/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);  // Distance of Person 1 from Person 3
        int dist2 = abs(y - z);  // Distance of Person 2 from Person 3

        if (dist1 < dist2){
           return 1;  // Person 1 reaches first
        } 
        else if (dist2 < dist1){
          return 2; // Person 2 reaches first
        } 
        else {
            return 0;  // Both reach at same time
        }
    }
};

int main() {
    Solution sol;

    cout << sol.findClosest(2, 7, 4) << endl; // Output: 1
    cout << sol.findClosest(2, 5, 6) << endl; // Output: 2
    cout << sol.findClosest(1, 5, 3) << endl; // Output: 0

    return 0;
}
