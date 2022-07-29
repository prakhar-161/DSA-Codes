#include<bits/stdc++.h>
using namespace std;

// 0 to n-1 : recursion and memoization
int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
    if(i == n-1) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = f(i+1, j, triangle, n, dp) + triangle[i][j];
    int diag = f(i+1, j+1, triangle, n, dp) + triangle[i][j];

    return dp[i][j] = min(down, diag);
} 

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return f(0, 0, triangle, n, dp);
}