// print 1 to n using recursion(backtracking) (i+1 not allowed)

#include<iostream>
using namespace std;

void func(int i, int n) {
    if(i<1) return;

    func(i-1,n);
    cout << i << " ";
}

int main() {
    int n;
    cin >> n;
    func(n,n);
    return 0;
}