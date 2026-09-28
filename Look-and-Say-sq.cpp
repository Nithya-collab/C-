
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n=5;
    string s="1";
    char curr;
    int count;
    string n_l="";
    cout << s << endl;
    for(int i=0;i<n;i++){
        curr=s[0];
        count=1;
        for(int j=1;j<s.size();j++){
            if(s[j]==curr){
                count++;

            }
            else{
                 n_l+=to_string(count)+curr;
                 curr=s[j];
                 count=1;
            }
        }
        n_l+=to_string(count)+curr;
        cout << n_l << endl;
        s=n_l;
        n_l="";
    }
    return 0;
}