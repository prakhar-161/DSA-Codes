#include<iostream>
#include<vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &arr) {
    int size = arr.size();
    vector<int> dp(size, 0);    
    dp[0] = arr[0];

    for(int i=1; i<size; i++) {
        int p = arr[i];
        if(i > 1) p += dp[i-2];
        int np = dp[i-1];

        dp[i] = max(p, np);
    }

    return dp[size-1];
}

int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> temp1, temp2;

    for(int i=0; i<n; i++) {
        if(i != 0) temp1.push_back(nums[i]);
        if(i != n-1) temp2.push_back(nums[i]);
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}