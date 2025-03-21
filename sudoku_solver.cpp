#include <bits/stdc++.h>
using namespace std;

int n = 9;

bool issafe(int row, int col, vector<vector<int>> &sudoku, int val) {
    for (int i = 0; i < n; i++) {
        if (sudoku[row][i] == val || sudoku[i][col] == val) return false;
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    return true;
}

bool solving(vector<vector<int>> &sudoku) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sudoku[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {  
                    if (issafe(i, j, sudoku, k)) {
                        sudoku[i][j] = k;  
                        if (solving(sudoku)) return true;
                        sudoku[i][j] = 0;  
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<int>> &sudoku) {
    solving(sudoku);
}

int main() {
    vector<vector<int>> sudoku(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sudoku[i][j];
        }
    }

    solve(sudoku);
    cout<<"The solution is ->"<<endl;
    for (auto row : sudoku) {
        for (auto col : row) cout << col << " ";
        cout << endl;  
    }

    return 0;
}
