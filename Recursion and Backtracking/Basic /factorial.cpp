// program to calculate factorial of a number through parameterized and functional recursion...
#include<iostream>
using namespace std;

// Parameterized recursion
void factorialP(int i, int fact) {
    if(i<1) {
        cout << fact << endl;
        return;
    }

    factorialP(i-1,fact*i);
}

// Functional recursion
int factorialF(int n) {
    if(n==0 || n==1) {
        return 1;
    }

    return (n * factorialF(n-1));
}

int main() {
    int n;
    cin >> n;
    // factorialP(n,1);
    cout << factorialF(n) << endl;
    return 0;
}