#include<iostream>
using namespace std;

int getIthBit(int n, int i) {
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}

int main() {
    int n, i;
    cin >> n >> i;

    cout << getIthBit(n,i) << endl;

    return 0;
}