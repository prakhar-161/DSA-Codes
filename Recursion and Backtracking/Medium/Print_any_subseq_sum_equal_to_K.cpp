#include<iostream>
#include<vector>
using namespace std;

bool printS(int ind, vector<int> &ds, int sum, int k, int arr[], int n) {
    if(ind == n) {
        // condition satisfied
        if(sum == k) {
            // for(auto it : ds) cout << it << " ";
            // cout << endl;
            return true;
        } 
        // condition not satisfied
        else {
            return false;
        }
    }

    // pick - left side
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if(printS(ind+1, ds, sum, k, arr, n) == true) return true;

    ds.pop_back();
    sum -= arr[ind];

    // not pick - right side
    if(printS(ind+1, ds, sum, k, arr, n) == true) return true;

    return false;
}

int main() {
    int arr[] = {2, 6, 4, 2};
    int n = 4;
    int k = 1;
    vector<int> ds;
    cout << printS(0, ds, 0, k, arr, n) << endl;

    return 0;
}