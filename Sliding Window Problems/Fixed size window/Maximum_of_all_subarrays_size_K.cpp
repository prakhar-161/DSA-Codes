// GFG
/*
    Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

    Input:
    N = 9, K = 3
    arr[] = 1 2 3 1 4 5 2 3 6
    Output: 
    3 3 4 5 5 5 6 

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(k)  
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<list>
using namespace std;

class Solution {
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k) {
        int i = 0, j = 0;
        list<int> l;
        vector<int> ans;
        while(j < n) {
            if(l.empty()) l.push_back(arr[j]);
            else {
                while(!l.empty() && l.back() < arr[j]) {
                    l.pop_back();
                }
                l.push_back(arr[j]);
            }

            if(j-i+1 < k) j++;
            else if(j-i+1 == k) {
                ans.push_back(l.front());
                if(l.front() == arr[i]) {
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};