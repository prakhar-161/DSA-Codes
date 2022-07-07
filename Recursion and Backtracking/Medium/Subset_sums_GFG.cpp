// GFG Problem
/*
    Given a list arr of N integers, print sums of all subsets in it.    
    Time Complexity: O(2^N)
    Auxiliary Space: O(2^N)
*/
// solution one - power set -> TC = O(n * 2^n)
// solution two - recursion

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void func(int ind, int sum, int N, vector<int> &arr, vector<int> &ans) {
        if(ind == N) {
            ans.push_back(sum);
            return;
        }

        // pick 
        func(ind+1, sum+arr[ind], N, arr, ans);

        // not pick
        func(ind+1, sum, N, arr, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        func(0, 0, N, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};