// Shortest path/distance in undirected graph with unit weights(no weights assigned to the edges)
// Using BFS algorithm

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    vector<int> findShortestDist(int N, vector<int> adj[], int src) {
        queue<int> q;
        vector<int> dist(N, INT_MAX);

        dist[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        for(auto it : dist) {
            cout << *it << " ";
        }
    }
};
