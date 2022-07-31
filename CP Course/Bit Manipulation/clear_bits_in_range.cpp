#include<iostream>
using namespace std;

// hard

int clearBitsInRange(int &n, int i) {
    int a = (-1 << (j+1));
    int b = (1 << i)-1;
    int mask = a | b;
    n = n & mask;
}

int main() {
    int n, i, j;
    cin >> n >> i >> j;

    clearBitsInRange(n, i, j);
    cout << n << endl;

    return 0;
}