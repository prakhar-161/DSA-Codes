// GFG
/*
    Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

    Input:
    N = 4, K = 2
    Arr = [100, 200, 300, 400]
    Output:
    700
    Explanation:
    Arr3  + Arr4 =700,
    which is maximum.
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
    public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N) {
        long maxSum = INT_MIN, sum = 0;
        int i = 0, j = 0;
        while(j < N) {
            sum = sum + Arr[j];

            if(j-i+1 < K) { j++ };

            else if(j-i+1 == K) {
                maxSum = max(maxSum, sum);
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
};