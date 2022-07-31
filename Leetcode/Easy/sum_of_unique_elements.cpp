#include<bits/stdc++.h>
using namespace std;

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(mp.count(nums[i]) == 0) {
            mp[nums[i]] = 1;
        } else {
            mp[nums[i]]++;
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        if(mp[nums[i]] == 1) sum += nums[i];
    }
    return sum;
}