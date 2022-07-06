// reverse array using only one pointer.

#include<iostream>
#include<utility>
#include<vector>
using namespace std;

// 1-pointer method
void func(int i, vector<int>& v) {
    int n = v.size();
    if(i>=n/2) return;

    swap(v[i],v[n-i-1]);
    func(i+1,v);
}

int main() {
    vector<int>v={1,2,3,4,5,6,7,8,9,10,15};
    func(0,v);
    cout << "Reversed vector is : ";
    for(auto it : v) {
        cout << it << " ";
    }   
    return 0;
}