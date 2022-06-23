// KAHN'S ALGORITHM

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    vector<int> topoSort(int N, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(N, 0);
        for(int i=0; i<N; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for(int i=0; i<N; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topoAns;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoAns.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topoAns;
    }
};