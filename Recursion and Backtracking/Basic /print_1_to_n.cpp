// print 1 to n linearly using recursion

#include<iostream>
using namespace std;

void printN(int i, int n) {
    if(i>n) return;
    cout << i << " ";
    printN(i+1,n);
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;
    printN(1,n);
    return 0;
}