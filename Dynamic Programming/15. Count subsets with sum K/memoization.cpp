#include<bits/stdc++.h>
using namespace std;

int f(int ind, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(tar == 0 && num[0] == 0) return 2;
        if(tar == 0 || tar == num[0]) return 1;
        return 0;
    }

    if(dp[ind][tar] != -1) return dp[ind][tar];

    int notPick = f(ind-1, tar, num, dp);
    int pick = 0;
    if(num[ind] <= tar) pick = f(ind-1, tar-num[ind], num, dp);

    return (pick + notPick);
}

int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return f(n-1, tar, num, dp);
}