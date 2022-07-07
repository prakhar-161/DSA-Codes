// Leetcode problem
/*
    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

    A palindrome string is a string that reads the same backward as forward.

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void func(int ind, string s, vector<string> &path, vector<vector<string>> &ans) {
        if(ind == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=ind; i<s.size(); i++) {
            if(isPalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i-ind+1));     // substr(starting index, size of substring to be taken)
                func(i+1, s, path, ans);
                path.pop_back();
            }   
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0, s, path, ans);
        return ans;
    }
};