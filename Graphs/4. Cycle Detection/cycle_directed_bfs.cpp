// using kahn's algorithm
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    bool isCycleDirBFS(int N, vector<int> adj[]) {
        queue<int> q;
        vector<int> indeg(N, 0);
        for(int i=0; i<N; i++) {
            for(auto it : adj[i]) {
                indeg[it]++;
            }
        }

        for(int i=0; i<N; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(auto it : adj[node]) {
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        if(count == N) return false;
        return true;
    }
};