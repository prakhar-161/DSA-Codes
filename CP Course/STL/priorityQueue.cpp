#include<iostream>
#include<queue>
using namespace std;

int main() {
    int arr[] = {10, 5, 6, 98, 13, 2};
    int n = sizeof(arr)/sizeof(int);

    priority_queue<int> heap;
    // By default, it is a max heap

    for(int x : arr) heap.push(x);

    while(!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }

    // we will get elements in descending order as by default it is max heap.

    cout << "\n";

    // To form and work with min heap, we do the following
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int x : arr) minHeap.push(x);

    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    // Now, we will get elements in ascending order.

    return 0;
}