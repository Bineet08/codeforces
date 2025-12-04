#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solve() {
    int q;
    cin >> q;
    
    deque<int> dq;
    long long rizziness = 0;
    long long sum = 0;
    bool reversed = false;
    
    for (int i = 0; i < q; ++i) {
        int s;
        cin >> s;
        
        if (s == 1) {
            // Cyclic shift
            if (dq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            
            if (!reversed) {
                int last = dq.back();
                dq.pop_back();
                rizziness -= last * dq.size() + last;
                sum -= last;
                dq.push_front(last);
                rizziness += last * 1;
                sum += last;
                rizziness += sum - last;
            } else {
                int first = dq.front();
                dq.pop_front();
                rizziness -= first * 1;
                sum -= first;
                dq.push_back(first);
                rizziness += first * dq.size();
                sum += first;
                rizziness -= (sum - first);
            }
        } else if (s == 2) {
            // Reverse the array
            reversed = !reversed;
        } else if (s == 3) {
            int k;
            cin >> k;
            if (!reversed) {
                dq.push_back(k);
                rizziness += k * dq.size();
                sum += k;
            } else {
                dq.push_front(k);
                rizziness += k * 1;
                sum += k;
                rizziness += sum - k;
            }
        }
        
        cout << rizziness << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}