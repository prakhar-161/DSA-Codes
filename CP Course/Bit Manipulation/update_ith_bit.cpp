#include<iostream>
using namespace std;

void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

void updateIthBit(int &n, int i, int v) {
    clearIthBit(n,i);
    int mask = (v << i);
    n = n | mask;
}

int main() {
    int n, i, v;
    cin >> n >> i >> v;

    updateIthBit(n,i,v);
    cout << n << endl;

    return 0;
}