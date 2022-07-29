#include<iostream>
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