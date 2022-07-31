#include<iostream>
#include<deque>
using namespace std;

/*
    Deque (Doubly Ended Queue)
    It is sequence containers with dynamic sizes that can be expanded or contracted on both ends (front or back)
    They are not guaranteed to store all the elements in contigous storage locations
    Accessing elements in a deque by offsetting a pointer to another element causes undefined behaviour
    Elements of a deque can be scattered in different chunks of storage

    * Can be used in sliding window problems
*/

/*
    Methods -
    [], at(), back(), begin(), capacity(), front(), clear(), empty(), end(), erase(), insert()
    pop_back(), pop_front(), push_back(), push_front(), size(), resize()
*/

int main() {
    deque<int> first;
    deque<int> second(5, 10);
    deque<int> third(second.begin(), second.end());     // iterating through second
    deque<int> fourth(third);                           // a copy of third

    // Other operations similar to vectors previously done before.
}