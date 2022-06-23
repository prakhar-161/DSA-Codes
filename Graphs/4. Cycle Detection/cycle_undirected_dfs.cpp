#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    bool checkCycleDFS(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        vis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checkCycleDFS(it, node, vis, adj)) return true;
            }
            else if(parent != it) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        for(int i=1; i<=V; i++) {
            if(!vis[i]) {
                if(checkCycleDFS(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};  