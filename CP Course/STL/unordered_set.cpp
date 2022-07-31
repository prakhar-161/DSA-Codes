#include<iostream>
#include<unordered_set>
using namespace std;

// Set is a collection of keys.
// Random order
// Each insertion is O(1)
// Search -> find -> O(1)
// Deletion -> erase -> O(1)

int main() {
    unordered_set<int> s{1,2,3,8,4,7,11,15,0};

    // insert
    s.insert(90);

    // erase()
    s.erase(3);

    int key;
    cin >> key;

    // find() -> O(1) time
    if(s.find(key) != s.end()) {                // if the travseral in set does not got to s.end(), it means key is found in it.
        cout << key << " is present" << "\n";
    } else {
        cout << "Not found" << "\n";
    }

    // Printing all the elements of unordered set
    // prints in RANDOM ORDER
    for(auto x : s) {
        cout << x << " ";
    } cout << "\n";

    return 0;
}