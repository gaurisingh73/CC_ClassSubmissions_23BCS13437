#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); 
    }

    vector<long long> dist(n + 1, 1e9);

    priority_queue<pair<long long,int>, 
                   vector<pair<long long,int>>, 
                   greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [next, weight] : adj[node]) {
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    if (dist[n] == 1e9) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    int curr = n;

    while (curr != -1) {
        path.push_back(curr);
    }

    reverse(path.begin(), path.end());

    for (int node : path) {
        cout << node << " ";
    }

    return 0;
}
