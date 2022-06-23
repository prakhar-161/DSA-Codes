// undirected

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool bipartiteDFS(int node, vector<int> adj[], int color[]) {
    if(color[node] == -1) color[node] = 0;              // for first node of a component
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDFS(it, adj, color)) return false;
        }
        else if(color[it] == color[node]) {
            return false;
        }
    }
    return true;
}

bool checkBipartite(int n, vector<int> adj[]) {
    int color[n];
    memset(color, -1, sizeof color);
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            if(!bipartiteDFS(i, adj, color)) return false;      // if any of the component is not bipartite, then the graph is not bipartite.
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite(n, adj)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}