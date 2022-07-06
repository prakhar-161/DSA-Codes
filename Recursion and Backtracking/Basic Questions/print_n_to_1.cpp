// print n to 1 using recursion

#include<iostream>
using namespace std;

void func(int i,int n) {
    if(i<1) return;
    cout << i << " ";
    func(i-1,n);
}

int main() {
    int n;
    cin >> n;
    func(n,n);
    return 0;
}