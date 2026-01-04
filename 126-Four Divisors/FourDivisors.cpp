// Problem Link: https://leetcode.com/problems/four-divisors/description
// Date: 04/01/2026
#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            int val = sumOne(n);
            if (val != -1)
                res += val;
        }
        return res;
    }

private:
    int sumOne(int n) {
        // Case 1: n = p^3 where p is prime → exactly 4 divisors
        int p = round(cbrt(n));
        if ((long long)p * p * p == n && isPrime(p)) {
            return 1 + p + p * p + p * p * p;
        }

        // Case 2: n = p * q where p and q are distinct primes
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int a = i;
                int b = n / i;
                if (a != b && isPrime(a) && isPrime(b)) {
                    return 1 + a + b + n;
                }
                return -1;
            }
        }
        return -1;
    }

    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {21, 4, 7};

    cout << "Sum of divisors for numbers with exactly four divisors: "
         << sol.sumFourDivisors(nums) << endl;

    return 0;
}
