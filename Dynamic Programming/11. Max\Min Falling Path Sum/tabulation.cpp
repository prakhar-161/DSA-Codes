#include<bits/stdc++.h>
using namespace std;

// Tabulation : (0 to n-1)
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    // Base case 
    for(int j=0; j<m; j++) {
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int up = matrix[i][j] + dp[i-1][j];

            int upperLeftDiag = matrix[i][j];
            if(j>0) upperLeftDiag += dp[i-1][j-1];
            else upperLeftDiag += -1e8;               // out of bound case

            int upperRightDiag = matrix[i][j];
            if(j+1<m) upperRightDiag += dp[i-1][j+1];
            else upperRightDiag += -1e8;              // out of bound case

            dp[i][j] = max(up, max(upperLeftDiag, upperRightDiag));
        }
    }

    int maxi = -1e8;
    for(int j=0; j<m; j++) {
        maxi = max(maxi, dp[n-1][j]);       // finding max of all the total values after calculation from last row for all columns.
    }

    return maxi;
}