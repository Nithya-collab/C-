// #include<iostream>
// using namespace std;

// int main(){
//     for(int i=0;i<7;++i){
//       for(int k=0;k<=i;++k)
//             cout<<" ";
//       for(int j=6;j>=i;--j){
//           if(j==0 || j == (7 - i - 1))
//             cout<<" * ";
//           else 
//             cout << " ";
// 	}
//       cout<<endl;
//     }
//     return 0;
// }



#include <iostream>
using namespace std;

int main() {
    int n = 7; 
    for (int i = 0; i < n; i++) {
        // 1. Leading spaces for alignment
        for (int k = 0; k < i; k++) {
            cout << " ";
        }

        // 2. V-shape logic
        for (int j = 0; j < (n - i); j++) {
            // Only print the first and last position of each row
            if (j == 0 || j == (n - i - 1)) {
                cout << " * ";
            } else {
                cout << "  "; // Two spaces to match "* "
            }
        }
        cout << endl;
    }
    return 0;
}



#include<iostream>
using namespace std;
int main(){
        int n = 7; 
        string s="PROGRAM";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (i == j) {
                cout << s[i] << " ";
            } 
            else if ( j == (n-i-1)){
                cout << s[j] << " ";
            }
            else {
                cout << " "; 
            }
        }
        cout << endl;
    }
    return 0;
}
