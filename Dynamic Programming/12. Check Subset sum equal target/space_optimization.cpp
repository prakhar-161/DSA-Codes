#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[i] <= target) take = prev[target-arr[i]];

            curr[target] = (take | notTake);
        }
        prev = curr;
    }
    return prev[k];
}

/*
    TC -> O(N * K)
    SC -> O(K)
*/