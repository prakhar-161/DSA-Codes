#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &nums, int tar) {
    int n = nums.size();
    vector<int> prev(tar+1, 0);

    prev[0] = 1;
    if(nums[0] <= tar) prev[nums[0]] = 1;

    for(int i=1; i<n; i++) {
        vector<int> curr(tar+1,0);
        curr[0]=1;
        for(int sum=1; sum<=tar; sum++) {
            int np = prev[sum];
            int p = 0;
            if(nums[i] <= tar) p = prev[sum-nums[i]];

            curr[sum] = p + np;
        }
        prev = curr;
    }
    return prev[tar];
}