//Problem Link: https://leetcode.com/problems/fraction-to-recurring-decimal/description
// Date: 24/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        // Case: numerator is 0
        if (numerator == 0) 
        {
            return "0";
        }

        string result = "";

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) 
        {
            result.push_back('-');
        }

        // Convert to long long to avoid overflow issues
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        long long integerPart = num / den;
        result += to_string(integerPart);

        long long remainder = num % den;

        // If no remainder, return integer part
        if (remainder == 0) 
        {
            return result;
        }

        result.push_back('.');

        // Map to store remainder -> index in result string
        unordered_map<long long, int> seen;

        while (remainder != 0) 
        {
            // If remainder already seen, repeating part found
            if (seen.count(remainder)) 
            {
                result.insert(seen[remainder], "(");
                result.push_back(')');
                break;
            }

            // Store current remainder with its position
            seen[remainder] = result.size();

            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};

int main() 
{
    Solution sol;

    cout << sol.fractionToDecimal(1, 2) << endl;     // "0.5"
    cout << sol.fractionToDecimal(2, 1) << endl;     // "2"
    cout << sol.fractionToDecimal(4, 333) << endl;   // "0.(012)"
    cout << sol.fractionToDecimal(1, 6) << endl;     // "0.1(6)"
    cout << sol.fractionToDecimal(-50, 8) << endl;   // "-6.25"
    cout << sol.fractionToDecimal(7, -12) << endl;   // "-0.58(3)"

    return 0;
}
