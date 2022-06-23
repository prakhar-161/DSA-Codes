#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        vector<int> bfs;

        for(int i=1; i<=V; i++) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
        return bfs;
    }
};