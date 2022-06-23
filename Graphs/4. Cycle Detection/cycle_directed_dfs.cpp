#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
    private: 
    bool checkCycleDFS(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checkCycleDFS(it, adj, vis, dfsVis)) return true;
            }
            else if(dfsVis[it]) return true; 
        }
        dfsVis[node] = 0;
        return false;
    }

    public:
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        vector<int> dfsVis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(checkCycleDFS(i, adj, vis, dfsVis)) return true;
            }
        }
        return false;
    }
};