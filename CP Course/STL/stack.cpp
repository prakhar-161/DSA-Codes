#include<iostream>
#include<stack>
#include<string>
using namespace std;

// LIFO

int main() {
    stack<string> names;

    names.push("kevin");
    names.push("aaron");
    names.push("roy");
    names.push("john");

    while(!names.empty()) {
        cout << names.top() << " ";
        names.pop();
    }

    return 0;
}