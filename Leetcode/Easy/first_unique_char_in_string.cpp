#include<bits/stdc++.h>
using namespace std;

// hashtable

int firstUniqueChar(string s) {
    unordered_map<char, int> mp;
    int n = s.size();

    // storing frequency of characters in map
    for(int i=0; i<n; i++) {
        if(mp.count(s[i]) == 0) {
            mp[s[i]] = 1;
        } else {
            mp[s[i]]++;
        }
    }

    // traversing through string and if frequency of any character comes to be 1, we return the index from there only.
    for(int i=0; i<n; i++) {
        if(mp[s[i]] == 1) return i;
    }
    return -1;
}