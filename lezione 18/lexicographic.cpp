#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, sol="";
    cin >> s;
    int n;
    n = s.length();
    char x, max='0';
    for(int i = n-1; i>=0; i--){
        x = s[i];
        if (x>= max){
            max= x; 
            sol+= x;
        }
    }
    reverse(sol.begin(),sol.end());
    cout << sol << endl;
}
