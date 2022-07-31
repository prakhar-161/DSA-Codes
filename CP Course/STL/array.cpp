#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

void updateArray(array<int,6> &arr, int i, int val) {
    arr[i] = val;
}

void printArray(const array<int,6> &arr) {
    // using const because printArray is a read-only function 
    // and we don't want any value of array to be be changed
    // so through const keyword, we ensure that
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    array<int,6> arr = {43,2,101,78,10,0};

    printArray(arr);
    updateArray(arr, 4, 55);
    printArray(arr);
    
    // arr.end() -> represents the index position after the last element in the array
    // so, last element will be : (arr.end()-1)

    // Sorting
    sort(arr.begin(), arr.end());
    printArray(arr);

    // Fill
    array<int,10> ones;
    ones.fill(1);
    for(int i=0; i<ones.size(); i++) {
        cout << ones[i] << " "; 
    } 
    cout << "\n";

    // For each loop
    for(int x : arr) cout << x << " ";
    cout << "\n";

    // Get ith element
    // at(index)
    cout << arr.at(3) << endl;

    cout << arr.front() << " " << arr.back() << endl;

    return 0;
}