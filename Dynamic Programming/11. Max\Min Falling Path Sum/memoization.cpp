#include<bits/stdc++.h>
using namespace std;

// memoization and recursion : (n-1 to 0)
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if(j<0 || j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = matrix[i][j] + f(i-1, j, matrix, dp);
    int upperLeftDiag = matrix[i][j] + f(i-1, j-1, matrix, dp);
    int upperRightDiag = matrix[i][j] + f(i-1, j+1, matrix, dp);

    return dp[i][j] = max(up, max(upperLeftDiag, upperRightDiag));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    int maxi = -1e8;
    // iterating for all columns for last row
    for(int j=0; j<m; j++) {
        // f(n-1, j, matrix, dp);
        maxi = max(maxi, f(n-1, j, matrix, dp));
    }

    return maxi;
}