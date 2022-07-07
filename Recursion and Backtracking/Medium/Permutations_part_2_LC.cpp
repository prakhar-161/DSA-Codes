/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]   

    Input: nums = [0,1]
    Output: [[0,1],[1,0]]

    ** This solution uses less space than the previous part-1.

    TC-> O(n! * n)
    SC-> O(n) => auxiliary
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void recurPermute(int ind, vector<int> &nums, vector<int> &ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            recurPermute(ind, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};