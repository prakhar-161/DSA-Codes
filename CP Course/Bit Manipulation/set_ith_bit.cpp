#include<iostream>
using namespace std;

void setIthBit(int &n, int i) {
    int mask = (1 << i);
    n = n | mask;
}

int main() {
    int n, i;
    cin >> n >> i;

    setIthBit(n,i);
    cout << n << endl;

    return 0;
}