/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]   

    Input: nums = [0,1]
    Output: [[0,1],[1,0]]

    ** This solution uses extra space complexity

    TC-> O(n! * n)
    SC-> O(n) + O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void recurPermute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int freq[]) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()] = {0};
        recurPermute(nums, ds, ans, freq);
        return ans;
    }
};