//GFG 
/*
    Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

    Input :
    A[] = {10, 5, 2, 7, 1, 9}
    K = 15
    Output : 4
    Explanation:
    The sub-array is {5, 2, 7, 1}.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).
*/

// **** Works for only positive integer array **** 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int lenOfLongSubarr(int A[],  int N, int K) { 
        int i=0, j=0, mx=0; 
        long int sum;
        while(j < N) {
            sum += A[j];
            if(sum < K) j++;
            else if(sum == K) {
                mx = max(mx, j-i+1);
                j++;
            }
            else {
                while(sum > K) {
                    sum -= A[i];
                    i++;
                }
                j++;
            }
        }
        return mx;
    } 

};