#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/* 
            map:
    numeric <-> associative 
(like array)     (custom indexes)
*/

int main() {
    map<int, string> customer;
    customer[100] = "sibghat";
    customer[123] = "ali";
    customer[144] = "sdsd";
    customer[150] = "uza";

    // Correct map initialization
    map<int, string> c{
        {100, "sibghat"},
        {123, "ali"},
        {144, "sdsd"},
        {150, "uza"},
    }; // Semicolon added here

    // Iterate and print map elements
    map<int, string>::iterator p = customer.begin();
    while (p != customer.end()) {
        cout << p->second << endl; // Corrected spelling of "second"
        p++;
    }

    return 0;
}
