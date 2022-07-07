/*
    TC -> O(n * 2^n)
    SC -> O(n)       (auxiliary)
*/

#include<iostream>
#include<vector>
using namespace std;

void printSubseq(int ind, vector<int> &ds, int arr[], int n) {
    if(ind == n) {
        for(auto it : ds) {
            cout << it << " ";
        }
        if(ds.size() == 0) cout << "{}";
        cout << endl;
        return;
    }

    // take in subsequence
    ds.push_back(arr[ind]);
    printSubseq(ind+1, ds, arr, n);
    ds.pop_back();

    // not take in subsequence
    printSubseq(ind+1, ds, arr, n);
}

int main() {
    int arr[] = {4, 5, 8};
    int n = 3;
    vector<int> ds;
    printSubseq(0, ds, arr, n);
    return 0;
}