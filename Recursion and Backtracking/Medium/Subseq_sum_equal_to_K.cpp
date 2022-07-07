#include<iostream>
#include<vector>
using namespace std;

void printS(int ind, vector<int> &ds, int sum, int k, int arr[], int n) {
    if(ind == n) {
        if(sum == k) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
        } 
        return;
    }

    // pick
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printS(ind+1, ds, sum, k, arr, n);

    ds.pop_back();
    sum -= arr[ind];

    // not pick
    printS(ind+1, ds, sum, k, arr, n);
}

int main() {
    int arr[] = {2, 6, 4, 2};
    int n = 4;
    int k = 6;
    vector<int> ds;
    printS(0, ds, 0, k, arr, n);

    return 0;
}