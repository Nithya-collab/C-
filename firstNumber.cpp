#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {

        int start = 1 + i * (i + 1) / 2;

        for (int j = 0; j < i + 1; j++) {
            cout << start + j << " ";
        }

        cout << endl;
    }

    return 0;
}