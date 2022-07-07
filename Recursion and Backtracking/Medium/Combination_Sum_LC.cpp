// Leetcode problem
/*
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
    void findCombination(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if(ind == arr.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }

        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target-arr[ind], arr, ds, ans);
            ds.pop_back();
        }
        findCombination(ind+1, target, arr, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ds, ans);
        return ans;
    }
};
