#include <iostream>
#include <string>
using namespace std;

// Reverses s[l..r] in place, inclusive on both ends.
void reverseRange(string& s, int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

int main() {
    string a = "abcd";
    reverseRange(a, 0, a.size() - 1);
    cout << a << "\n";          // expected: dcba

    string b = "the sky is blue";
    reverseRange(b, 0, b.size() - 1);
    cout << b << "\n";          // expected: eulb si yks eht

    string c = "hello world";
    reverseRange(c, 0, 4);      // only the first word
    cout << c << "\n";          // expected: olleh world

    string d = "x";
    reverseRange(d, 0, 0);      // single character, nothing changes
    cout << d << "\n";          // expected: x

    return 0;
}