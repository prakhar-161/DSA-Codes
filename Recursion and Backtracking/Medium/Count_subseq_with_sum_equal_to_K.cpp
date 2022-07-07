#include<iostream>
#include<vector>
using namespace std;

int printS(int ind, int sum, int k, int arr[], int n) {
    if(sum > k) return 0;
    if(ind == n) {
        if(sum == k) return 1;
        else return 0;
    }

    // pick - left side
    sum += arr[ind];
    int l = printS(ind+1, sum, k, arr, n);

    sum -= arr[ind];
    // not pick - right side
    int r = printS(ind+1, sum, k, arr, n);
    
    return l + r;
}

int main() {
    int arr[] = {2, 6, 4, 2};
    int n = 4;
    int k = 6;
    cout << printS(0, 0, k, arr, n) << endl;

    return 0;
}