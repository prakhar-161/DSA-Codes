#include<iostream>
#include<vector>
using namespace std;

int main() {
    // adjacency list
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        // weighted undirected graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return 0;
}