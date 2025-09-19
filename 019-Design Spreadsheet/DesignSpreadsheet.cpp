//Problem Link: https://leetcode.com/problems/design-spreadsheet/description
//Date: 19/09/2025
#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; // 2D grid for values

    // Helper: parse cell reference "A1" -> (row, col)
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0]; 
        int col = colChar - 'A'; 
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }

    // Helper: check if string is integer
    bool isInteger(const string &s) {
        return all_of(s.begin(), s.end(), ::isdigit);
    }

    // Helper: get value from cell reference or integer
    int getVal(const string &token) {
        if (isInteger(token)) {
            return stoi(token);
        } else {
            auto [r, c] = parseCell(token);
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        // formula looks like "=X+Y"
        string expr = formula.substr(1); // remove '='
        size_t plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);
        return getVal(left) + getVal(right);
    }
};

int main() {
    // Example run from problem statement
    Spreadsheet spreadsheet(3);
    cout << spreadsheet.getValue("=5+7") << endl; // 12
    spreadsheet.setCell("A1", 10);
    cout << spreadsheet.getValue("=A1+6") << endl; // 16
    spreadsheet.setCell("B2", 15);
    cout << spreadsheet.getValue("=A1+B2") << endl; // 25
    spreadsheet.resetCell("A1");
    cout << spreadsheet.getValue("=A1+B2") << endl; // 15
    return 0;
}
