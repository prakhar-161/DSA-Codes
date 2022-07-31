#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (target+1, 0));

    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(nums[0] <= target) dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++) {
        for(int sum=1; sum<=target; sum++) {
            int notPick = dp[i-1][sum];
            int pick = 0;
            if(nums[i] <= target) pick = dp[i-1][sum-nums[ind]];

            dp[i][sum] = notPick + pick;
        }
    }
    return dp[n-1][target];
}