// THE CODE WAS ASKED IN KOTLIN LANGUAGE SO USED CHATGPT FOR TRANSLATION :)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;

    if (n < 3) {
        cout << n << endl;
    } else if (n == 4 || n == 7) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// KOTLIN CODE-->
/*
fun solve() {
    val n = readLine()!!.toLong()

    if (n < 3) {
        println(n)
    } else if (n == 4L || n == 7L) {
        println(1)
    } else {
        println(0)
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        solve()
    }
}
*/