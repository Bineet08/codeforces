#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;  // Number of test cases
    cin >> t;
    
    while (t--) {
        int n;  // Size of the grid
        cin >> n;
        
        vector<int> grid;
        
        // Reading the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val;
                cin >> val;
                grid.push_back(val);
            }
        }
        
        // Sorting the collected values to form the permutation
        sort(grid.begin(), grid.end());
        
        // Output the result as the permutation
        for (int i = 0; i < 2 * n; ++i) {
            cout << grid[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
