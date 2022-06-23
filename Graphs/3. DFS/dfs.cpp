#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& storeDfs) {
        storeDfs.push_back(node);
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, storeDfs);
            } 
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        vector<int> storeDfs;

        for(int i=1; i<=V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, storeDfs);
            }
        }
        return storeDfs;
    }
};