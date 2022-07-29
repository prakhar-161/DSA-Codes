#include<bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int> (n, 0));

    // Base case
    // assigning values to the last row of the dp array of triangle
    for(int j=0; j<n; i++) {
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int down = dp[i+1][j] + triangle[i][j];
            int diag = dp[i+1][j+1] + triangle[i][j];

            dp[i][j] = min(down, diag);
        }
    }

    return dp[0][0];
}