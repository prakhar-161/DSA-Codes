#include<iostream>
using namespace std;

void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

int main() {
    int n, i;
    cin >> n >> i;

    clearIthBit(n,i);
    cout << n << endl;

    return 0;
}