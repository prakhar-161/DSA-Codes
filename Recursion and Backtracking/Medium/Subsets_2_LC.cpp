// Leetcode Problem
/*
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<int> &ans){
        ans.push_back(ds);
        for(int i=ind; i<nums.size(); i++) {
            if(i != ind && nums[i] == nums[ind]) continue;
            ds.push_back(nums[i]);
            findSubsets(ind+1, nums, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};


// first level of recursion tree made sure empty subset is generated.
// second level of recursion tree made sure subset of size 1 are generated.
// third level of recursion tree made sure subset of size 2 are generated.
// fourth level of recursion tree made sure subset of size 3 are generated.
// and so on.