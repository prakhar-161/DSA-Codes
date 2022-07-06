#include<iostream>
using namespace std;

int cnt = 0;
void printVal() {
    if(cnt==5) return;
    cout << cnt << " ";
    cnt++;
    printVal();
}

int main() {
    printVal();
    return 0;
}