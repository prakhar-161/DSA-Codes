#include<iostream>
#include<vector>
using namespace std;

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int l = dp[i-1] + abs(heights[i] - heights[i-1]);
        int r = INT_MAX;
        if(i > 1) r = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(l,r);
    }

    return dp[n-1];
}