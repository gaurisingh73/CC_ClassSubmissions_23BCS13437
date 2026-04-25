#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

vector<int> parent, rankSet;
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (rankSet[rootA] < rankSet[rootB])
            parent[rootA] = rootB;
        else if (rankSet[rootA] > rankSet[rootB])
            parent[rootB] = rootA;
        else {
            parent[rootB] = rootA;
            rankSet[rootA]++;
        }
    }
}

int main() {
    int V = 4; 
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    sort(edges.begin(), edges.end(), cmp);

    parent.resize(V);
    rankSet.resize(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            unionSet(e.u, e.v);
        }
    }

    cout << "Edges in MST:\n";
    for (auto e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    cout << "Total Weight: " << totalWeight << endl;

    return 0;
}
