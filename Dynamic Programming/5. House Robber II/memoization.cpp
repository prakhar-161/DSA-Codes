// Leetcode - House robber 2
/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array arr representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    Input: arr = [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

    Input: arr = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
*/

#include<iostream>
#include<vector>
using namespace std;

int f(int ind, vector<int> &arr, vector<int> &dp) {
    if(ind == 0) return arr[ind];
    if(ind < 1) return 0;

    if(dp[ind] != -1) return dp[ind];

    int p = arr[ind] + f(ind-2, arr, dp);
    int np = 0 + f(ind-1, arr, dp);

    return dp[ind] = max(p, np);
}

int maximumNonAdjacentSum(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(n-1, arr, dp);
}

int rob(vector<int>& nums) {
    vector<int> temp1, temp2;
    int n = nums.size();
    if(n==1) return nums[0];
    for(int i=0; i<n; i++) {
        if(i != 0) temp1.push_back(nums[i]);          // Not considering the first element
        if(i != n-1) temp2.push_back(nums[i]);        // Not considering the last element
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}

