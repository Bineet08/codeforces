#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    map<pair<int, int>, int> mp;
    vector<int> s;

    // Input the array of pairs
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        ++mp[{arr[i].first, arr[i].second}];
        // Collect values where first == second and count is 1
        if (arr[i].first == arr[i].second && mp[{arr[i].first, arr[i].first}] == 1) {
            s.push_back(arr[i].first);
        }
    }

    // Sort the unique values where first == second
    sort(s.begin(), s.end());

    // Iterate through the pairs and calculate results
    for (int i = 0; i < n; ++i) {
        if (arr[i].first == arr[i].second) {
            // Check if it's a unique pair
            if (mp[{arr[i].first, arr[i].first}] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            // Use binary search to find the range in the sorted vector
            int r = distance(begin(s), upper_bound(begin(s), end(s), arr[i].second));
            int l = distance(begin(s), lower_bound(begin(s), end(s), arr[i].first));
            int dx = r - l;
            int d = arr[i].second - arr[i].first + 1;

            // Check the condition for output
            if (d > dx) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
