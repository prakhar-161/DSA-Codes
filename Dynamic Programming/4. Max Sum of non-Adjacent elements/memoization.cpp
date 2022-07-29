// CodeStudio
/*
    You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

    Input :
    2
    3
    1 2 4
    4
    2 1 4 9

    Output : 
    5
    11
*/

// Similar to House Robber on leetcode

#include <iostream>
#include <vector>
using namespace std;

int f(int ind, vector<int> &nums, vector<int> &dp) {
    if(ind == 0) return nums[ind];
    if(ind < 1) return 0;

    if(dp[ind] != -1) return dp[ind];

    int p = nums[ind] + f(ind - 2, nums, dp);
    int np = f(ind - 1, nums, dp);

    return dp[ind] = max(p,np);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n-1, nums, dp);
}