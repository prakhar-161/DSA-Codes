#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for(int i=0; i<n; i++) totalSum += arr[i];

    int k = totalSum;
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
    // So here, dp[n-1][col->0...totalSum] will return us the answer needed
    int mini = 1e9;
    for(int s1=0; s1<=totalSum/2; s1++) {
        if(dp[n-1][s1] == true) {                       
            mini = min(mini, abs((totalSum - s1) - s1));
        }
    }

    return mini;
}