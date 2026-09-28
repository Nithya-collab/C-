#include <iostream>
using namespace std;

int main() {
    int n = 4; // Height of the V
    int width = 2 * n - 1; // Total width across the top

    // Loop through each row
    for (int i = 0; i < n; i++) {
        
        // Loop through each column in the current row
        for (int j = 0; j < width; j++) {
            
            // Print a star if it's the left diagonal OR the right diagonal
            if (j == i || j == width - 1 - i) {
                cout << "*";
            } else {
                cout << " "; // Print a space everywhere else
            }
        }
        cout << endl; // Move to the next line after finishing the row
    }

    return 0;
}