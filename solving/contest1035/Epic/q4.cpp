#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int maxVal;
public:
    FenwickTree(int n) : maxVal(n + 1), bit(n + 2, 0) {}
    void update(int idx, int delta) {
        for (; idx <= maxVal; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
};

vector<int> compress(const vector<int>& arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    return sorted;
}

int getIndex(const vector<int>& compressed, int val) {
    return lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin() + 1;
}

bool canMakePalindrome(int n, int k, const vector<int>& arr) {
    vector<int> compressed = compress(arr);
    FenwickTree ft(compressed.size());
    
    // Initialize frequency counts
    for (int x : arr) {
        ft.update(getIndex(compressed, x), 1);
    }

    int left = 0, right = n - 1;
    while (left < right) {
        if (arr[left] == arr[right]) {
            left++;
            right--;
            continue;
        }
        
        int leftVal = arr[left], rightVal = arr[right];
        int leftFreq = ft.query(getIndex(compressed, leftVal));
        int rightFreq = ft.query(getIndex(compressed, rightVal));
        
        if (leftFreq < k && rightFreq < k) {
            return false;
        }
        
        // Remove the element with sufficient frequency, preferring the larger value
        if (leftFreq >= k && (rightFreq < k || leftVal > rightVal)) {
            ft.update(getIndex(compressed, leftVal), -1);
            left++;
        } else {
            ft.update(getIndex(compressed, rightVal), -1);
            right--;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << (canMakePalindrome(n, k, arr) ? "YES" : "NO") << '\n';
    }
    return 0;
}