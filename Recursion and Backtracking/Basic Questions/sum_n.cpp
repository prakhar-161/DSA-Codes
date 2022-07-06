#include<iostream>
using namespace std;

// Parameterized recursion
void sumNP(int i, int sum) {
    if(i<1) {
        cout << sum << endl;
        return;
    }

    sumNP(i-1,sum+i);
}

// Functional recursion
int sumNF(int n) {
    if(n==0) return 0;

    return (n + sumNF(n-1));
}

int main() {
    int n;
    cin >> n;
    // sumNP(n,0);
    cout << sumNF(n) << endl;
    return 0;
}