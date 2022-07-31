// CodeStudio
#include<bits/stdc++.h>
using namespace std;

// DP on Subsequence/subset

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(ind == 0) return (arr[ind] == target);   // if 0th element equals to target

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind-1, target, arr, dp);
    bool take = false;      
    if(arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);   // check if ith element to be taken is not greater than target
    
    return (take | notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return f(n-1, k, arr, dp);
}

/*
    TC -> O(N * K)
    SC -> O(N * K) + O(N)
*/