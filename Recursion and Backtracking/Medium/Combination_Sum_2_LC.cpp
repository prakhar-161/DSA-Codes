// Leetcode problem
/*
    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.
    Also the solution should be sorted in ascending order.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void findCombination(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        } 

        for(int i=ind; i < arr.size(); i++) {
            if(i > ind && arr[i]==arr[ind]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(ind+1, target-arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination(0, target, candidates, ds, ans);
        return ans;
    }
};