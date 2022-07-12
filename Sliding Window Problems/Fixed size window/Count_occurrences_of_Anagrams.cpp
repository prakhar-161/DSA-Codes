// GFG
/*
    Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

    Input:
    txt = forxxorfxdofr
    pat = for
    Output: 3
    Explanation: for, orf and ofr appears
    in the txt, hence answer is 3.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(26) or O(256)
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int search(string s, string p) {
	
}

int main() {
    string s,p;
    cin >> s;
    cin >> p;

    cout << countOccurrence(p, s) << "\n";
    return 0;
}

