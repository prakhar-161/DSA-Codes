#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> prev(k+1, 0), curr(k+1,0);
    prev[0] = curr[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;

    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[i] <= target) take = prev[target - arr[i]];

            curr[target] = (take | notTake);
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];

    if(sum%2 != 0) return false;

    int k = sum / 2;

    return subsetSumToK(n-1, k, arr);
}