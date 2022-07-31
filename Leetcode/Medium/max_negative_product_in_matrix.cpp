#include<bits/stdc++.h>
using namespace std;

// Memoization
// int mod = 1e9+7;
// int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//     if(i==0 && j==0) return grid[i][j];
//     if(i<0 || j<0) return -1e8;

//     if(dp[i][j] != -1) return dp[i][j];

//     int up = f(i-1,j,grid,dp) * grid[i][j];
//     int left = f(i,j-1,grid,dp) * grid[i][j];

//     int ans = max(up, left);
//     if(ans < 0) return dp[i][j] = -1;
//     else return dp[i][j] = ans % mod;
// }

// int maxProductPath(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int> (n, -1));

//     return f(m-1, n-1, grid, dp);
// }
