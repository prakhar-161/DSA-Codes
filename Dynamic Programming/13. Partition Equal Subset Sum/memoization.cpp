// CodeStudio
#include<bits/stdc++.h>
using namespace std;

// DP on subsets

bool subsetSumToK(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(ind == 0) return (arr[ind] == target);  

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind-1, target, arr, dp);
    bool take = false;      
    if(arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);  

    return (take | notTake);
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];

    if(sum%2 != 0) return false;

    int k = sum / 2;
    vector<vector<int>> dp(n, vector<int> (k+1, -1));

    return subsetSumToK(n-1, k, arr, dp);
}

/* IMPORTANT */
// Returns TLE in some test cases 