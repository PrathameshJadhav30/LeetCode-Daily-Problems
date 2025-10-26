//Problem Link: https://leetcode.com/problems/simple-bank-system/description
//Date: 26/10/2025
#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    vector<long long> bal; // stores balance of each account
    int n;                 // total number of accounts

    // Helper function to check valid account number
    bool valid(int acc) {
        return acc > 0 && acc <= n;
    }

public:
    // Constructor: initializes the balance vector
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    // Transfer amount from one account to another
    bool transfer(int from, int to, long long amt) {
        if (!valid(from) || !valid(to) || bal[from - 1] < amt)
            return false;
        bal[from - 1] -= amt;
        bal[to - 1] += amt;
        return true;
    }

    // Deposit amount into account
    bool deposit(int acc, long long amt) {
        if (!valid(acc)) return false;
        bal[acc - 1] += amt;
        return true;
    }

    // Withdraw amount from account
    bool withdraw(int acc, long long amt) {
        if (!valid(acc) || bal[acc - 1] < amt)
            return false;
        bal[acc - 1] -= amt;
        return true;
    }

    // Display current balances
    void displayBalances() {
        cout << "Current Account Balances:\n";
        for (int i = 0; i < n; i++) {
            cout << "Account " << i + 1 << ": " << bal[i] << endl;
        }
    }
};

int main() {
    vector<long long> initialBalances = {1000, 2000, 3000, 4000, 5000};
    
    // Create Bank object
    Bank bank(initialBalances);

    cout << "Initial Balances:\n";
    bank.displayBalances();
    cout << "-----------------------------\n";

    // Perform some operations
    cout << "Withdraw 500 from Account 1: " 
         << (bank.withdraw(1, 500) ? "Success" : "Failed") << endl;

    cout << "Deposit 1000 into Account 2: " 
         << (bank.deposit(2, 1000) ? "Success" : "Failed") << endl;

    cout << "Transfer 1500 from Account 3 to Account 5: " 
         << (bank.transfer(3, 5, 1500) ? "Success" : "Failed") << endl;

    cout << "-----------------------------\n";
    bank.displayBalances();

    return 0;
}
