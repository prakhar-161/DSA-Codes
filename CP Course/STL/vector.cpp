#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Vectors - 
    Dynamic arrays with the ability to resize itself automatically when an element is inserted.
    Contigous store locations, reallocation happens when underlying array is full.
*/

void printVec(vector<int> &v) {
    for(int i=0; i<v.size(); i++) cout << v.at(i) << " ";
    cout << "\n";
}

int main() {
    // Empty vector construction
    vector<int> first;

    // Fill constructor (4 integers with value 10)
    vector<int> second(4, 10);

    // Range constructor
    int nums[] = {10,20,30,40,50};
    vector<int> third(nums, nums+5);

    // Copy constructor - copy a vector from another vector
    vector<int> fourth(third);      

    // Initialization list
    vector<int> v = {3,2,5,9,4,1,0};

    cout << v.at(4) << endl;

    cout << v.size() << endl;

    cout << v.capacity() << endl;

    // cout << v.max_size() << endl;

    // push_back() method -> O(1), linear if re-allocation happens
    v.push_back(10);
    v.push_back(99);
    printVec(v);

    v.pop_back();
    printVec(v);

    // erase() method
    // erase the 5th element
    v.erase(v.begin() + 4);
    printVec(v);

    // erase the range - first 3 elements
    v.erase(v.begin(), v.begin() + 3);
    printVec(v);

    // clear all elements in the current vector, reduces size to 0, 
    // but capacity does not change
    // v.clear();

    // reserve() - reserves the capacity of the vector to avoid doubling of it which is an expensive operation

    // Sorting
    // sort(v.begin(), v.end());

    return 0;
}