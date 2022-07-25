// Leetcode
/*
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Input: n = 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
*/


#include<iostream>
#include<vector>
using namespace std;

int climbingStairs(int n, vector<int>& dp) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(dp[n] != -1) return dp[n];

    return dp[n] = climbingStairs(n-1, dp) + climbingStairs(n-2, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);

    cout << climbingStairs(n, dp) << "\n";
    return 0;
}