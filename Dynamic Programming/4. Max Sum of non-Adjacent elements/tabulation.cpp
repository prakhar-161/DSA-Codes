#include<iostream>
#include<vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int i=1; i<n; i++) {
        int p = nums[i];
        if(i > 1) p += dp[i-2];
        int np = 0 + dp[i-1];

        dp[i] = max(p ,np);
    }

    return dp[n-1];
}