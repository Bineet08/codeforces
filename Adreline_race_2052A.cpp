#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int n;
	cin>>n;
	vector<bool> overtake(n+1);
	vector<array<int, 2>> ans;
	for(int i = 0; i < n; ++i) {
		int cars;
		cin >> cars;
		overtake[cars] = 1;
		for(int i = cars; i <= n; ++i) {
		    if(!overtake[i]) {
			    ans.push_back({i, cars});
		    }
		}
		for(int i = n; i >= 1; --i) {
		    if(!overtake[i]) {
			    ans.push_back({cars, i});
		    }
		}
	}
	cout << ans.size() << endl;
	for(auto& [a,b] : ans) {
	    cout << a << ' ' << b << endl;
	}
	return 0;
}