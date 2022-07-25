#include<iostream>
using namespace std;

int climbStairs(int n) {
    int p2 = 1, p1 = 1;
    for(int i=2; i<=n; i++) {
        int curr = p2 + p1;
        p2 = p1;
        p1 = curr;
    }
    return p1;
}

int main() {
    int n;
    cin >> n;

    cout << climbStairs(n) << "\n";
    return 0;
}