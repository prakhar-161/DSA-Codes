// undirected graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m, src;
    cin >> n >> m;
    vector<pair<int, int>> g[n+1];

    int u, w, wt;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> wt;
        g[u].push_back(make_pair(v, wt));
        g[v].push_back(make_pair(u, wt));
    }

    cin >> src;

    // beginning of dijsktra's algo
    // use priority queue as minHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX);             // stores the distances of all nodes from the source

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for(auto it : g[node]) {
            if(dist[it.first] > it.second + dist[node]) {                       // Also, dist[node] == dis
                dist[it.first] = it.second + dist[node];
                pq.push(make_pair(dist[it.first], it.first));
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << dist[i] << " ";
    } cout << endl;
    
    return 0;
}