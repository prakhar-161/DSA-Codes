// find shortest path in a directed acyclic graph

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void topoSort(int node, vector<int>& vis, stack<int>& st, vector<pair<int, int>> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            topoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int src, int N, vector<pair<int, int>> adj[]) {
    vector<int> vis(N, 0);
    stack<int> st;

    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            topoSort(i, vis, st, adj);
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        
        if(dist[node] != INT_MAX) {
            for(auto it : adj[node]) {
                if(dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        (dist[i] != INT_MAX) ? cout << "INF" << "\n" : cout << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
    }

    shortestPath(0, n, adj);

    return 0;
}