#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));

    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target) take = dp[i-1][target-arr[i]];

            dp[i][target] = (take | notTake);
        }
    }    
    return dp[n-1][k];
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];

    if(sum%2 != 0) return false;

    int k = sum / 2;

    return subsetSumToK(n-1, k, arr, dp);
}

// No TLE in this case
