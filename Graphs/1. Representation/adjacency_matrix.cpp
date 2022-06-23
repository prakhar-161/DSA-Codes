#include<iostream>
#include<vector>
using namespace std;

int main() {
    // adjacency matrix
    int n, m;
    cin >> n >> m;

    int adj[n+1][n+1];
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}