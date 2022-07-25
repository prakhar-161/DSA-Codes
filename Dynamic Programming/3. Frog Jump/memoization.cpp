// Code Studio
/*
    There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
    
    For Example - 
    If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 2
*/

#include<iostream>
#include<vector>
using namespace std;

int f(int ind, vector<int> &heights, vector<int> &dp) {
    if(ind == 0) return 0;     
    if(dp[ind] != -1) return dp[ind];

    int l = f(ind-1) + abs(heights[ind] - heights[ind-1]);
    int r = INT_MAX;
    if(ind > 1) r = f(ind-2) + abs(heights[ind] - heights[ind-2]);

    return dp[ind] = min(l,r);
}

int frogJump(int n, vector<int>& heights) {
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

