#include<iostream>
using namespace std;

int frogJump(int n, vector<int> &heights) {
    int prev=0, prev2=0;
    for(int i=1; i<n; i++) {
        int l = prev + abs(heights[i] - heights[i-1]);
        int r = INT_MAX;
        if(r > 1) r = prev2 + abs(heights[i] - heights[i-2]);

        int curr = min(l,r);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}