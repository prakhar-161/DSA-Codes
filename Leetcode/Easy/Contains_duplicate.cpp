#include <bits/stdc++.h>
using namespace std;

// hashtable

bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, bool> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(nums[i]) == 1) return true;
        mp[nums[i]] = false;
    }
    return false;
}