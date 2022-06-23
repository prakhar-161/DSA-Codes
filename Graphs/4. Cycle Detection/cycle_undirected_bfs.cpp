#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    bool checkCycleBFS(int z, int V, vector<int>& vis, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({z, -1});
        vis[z] = true;
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push({it, node});
                    vis[it] = true;
                }
                else if(parent != it) return true;      // if node has been visited and the adjacent node is not equal to its parent node.
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        for(int i=1; i<=V; i++) {
            if(!vis[i]) {
                if(checkCycleBFS(i, V, vis, adj)) return true;
            }
        }
        return false;
    }
};