// undirected

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

bool bipartiteBFS(int z, vector<int> adj[], int color[]) {
    queue<int> q;
    q.push(z);
    color[z] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(int n, vector<int> adj[]) {
    int color[n];
    memset(color, -1, sizeof color);
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            if(!bipartiteBFS(i, adj, color)) return false;           // if odd cycle, returns false, else true for all
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