#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> enemy_arrival(n + 1, INF);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            // BFS from a to find shortest path to b
            vector<int> parent(n + 1, -1);
            vector<bool> vis(n + 1, false);
            queue<int> q;
            q.push(a);
            vis[a] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }

            // Reconstruct path from a to b
            vector<int> path;
            for (int cur = b; cur != -1; cur = parent[cur])
                path.push_back(cur);
            reverse(path.begin(), path.end());

            for (int t = 0; t < path.size(); ++t) {
                int node = path[t];
                enemy_arrival[node] = min(enemy_arrival[node], t + 1);
            }
        }

        // BFS for Marat
        queue<pair<int, int>> q;
        vector<int> visited_time(n + 1, INF);
        q.push({x, 1});
        visited_time[x] = 1;

        int answer = -1;

        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();

            if (u == y) {
                answer = t;
                break;
            }

            // Stay
            if (t + 1 < enemy_arrival[u] && t + 1 < visited_time[u]) {
                visited_time[u] = t + 1;
                q.push({u, t + 1});
            }

            // Move
            for (int v : adj[u]) {
                if (t + 1 < enemy_arrival[v] && t + 1 < visited_time[v]) {
                    visited_time[v] = t + 1;
                    q.push({v, t + 1});
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
