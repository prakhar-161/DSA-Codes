#include<iostream>
#include<unordered_map>
using namespace std;

/*
    Unordered Map - 
    count() - returns the number of elements matching specific key, return 1 or 0
*/

int main() {
    unordered_map<string, int> menu;

    // Inserting key-value pairs inside the hash table in O(1) 
    menu["maggi"] = 15;
    menu["colddrink"] = 20;
    menu["dosa"] = 99;
    menu["pizza"] = 399;
    menu["thali"] = 499;

    // Deletion
    menu.erase("dosa");

    // Searching inside a collection of key-value pairs (stored inside a hashtable) in O(1)   
    string item;
    cin >> item;

    if(menu.count(item) == 0) {
        cout << item << " is not present" << "\n";
    }
    else {
        cout << item << " is available and its cost is " << menu[item] << "\n";
    }

    // Iterating over all the key-value pairs that are present - O(N)
    // Random order
    for(pair<string, int> item : menu) {
        cout << item.first << " - " << item.second << "\n";
    }cout << endl;

    // If we want to get the output in a lexicographic sorted order, that is alphabetically ordered,
    // then we can use a map instead of unordered map.
    // Then, all the O(1) queries will take O(logN) time 

    return 0;
}