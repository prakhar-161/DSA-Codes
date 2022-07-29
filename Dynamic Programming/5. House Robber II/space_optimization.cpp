#include<iostream>
#include<vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    int prev = nums[0], prev2 = 0;

    for(int i=1; i<n; i++) {
        int p = nums[i];
        if(i > 1) p += prev2;
        int np = 0 + prev;

        int curr = max(p, np);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int>& nums) {
    vector<int> temp1, temp2;
    int n = nums.size();
    if(n==1) return nums[0];
    for(int i=0; i<n; i++) {
        if(i != 0) temp1.push_back(nums[i]);          
        if(i != n-1) temp2.push_back(nums[i]);        
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}