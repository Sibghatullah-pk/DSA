#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(int n, int row, vector<int>& queens, map<int, bool>& column, 
           map<int, bool>& diag1, map<int, bool>& diag2, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(queens);  // Store the solution
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (column[col] || diag1[row - col] || diag2[row + col]) continue;

        // Place the queen
        queens[row] = col;
        column[col] = diag1[row - col] = diag2[row + col] = true;

        // Recurse to the next row
        solve(n, row + 1, queens, column, diag1, diag2, solutions);

        // Backtrack
        column[col] = diag1[row - col] = diag2[row + col] = false;
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> solutions;          // To store solutions
    vector<int> queens(n, -1);              // Tracks queen positions in each row
    map<int, bool> column, diag1, diag2;    // Maps for conflicts

    solve(n, 0, queens, column, diag1, diag2, solutions);
    return solutions;
}

void printSolutions(const vector<vector<int>>& solutions, int n) {
    for (const auto& queens : solutions) {
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                cout << (queens[row] == col ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> solutions = nQueen(n);

    cout << "Total solutions: " << solutions.size() << endl;
    printSolutions(solutions, n);

    return 0;
}
