#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

#define endl '\n'

long long p2[19];
long long p5[19];

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

vector<int>factors(int a){
    vector<int> res(2,0);
    while(a>0 && a%2==0){
        a /= 2;
        res[0]++;
    }
    while(a>0 && a%5==0){
        a /= 5;
        res[1]++;
    }
    return res;
}

void solve() {
     // Cursor position after snippet insertion
     int n,m;
     cin>>n>>m;
    vector<int> divideN = factors(n);
    int c2= divideN[0];
    int c5 = divideN[1];
    for (int dig = 18; dig >= 0; dig--) {
				int extra2 = max(0, dig - c2);
				int extra5 = max(0, dig - c5);
				long long need = p2[extra2] * p5[extra5];
				if (need <= m) {
						int largestK = m - m % need;
						cout << 1LL * largestK * n << '\n';
						return;
				}
            }
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    p2[0] = 1;
	p5[0] = 1;
    for (int i = 1; i <= 18; i++) {
			p2[i] = 2 * p2[i - 1];
			p5[i] = 5 * p5[i - 1];
	}
    while (t--) {
        solve();
    }
    return 0;
}