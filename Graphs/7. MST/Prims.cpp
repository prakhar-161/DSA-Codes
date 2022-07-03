#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// TC -> O(N + E + N*LOG(N)) ~ O(N*LOG(N))

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    int u, v, wt;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    vector<int> parent(n), key(n, INT_MAX);
    vector<bool> mst(n, false);

    // priority queue -> (wt, index(or node))
    priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});
    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;
        
        for(auto it : adj[node]) {
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false && weight < key[v]) {
                parent[v] = node;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << parent[i] << " - " << i << "\n";
    }

    return 0;
}

// 6 7 
// 0 1 5 
// 0 2 10 
// 0 3 100 
// 1 3 50 
// 1 4 200
// 3 4 250
// 4 5 50 