#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, sol;
    cin >> s;
    int n;
    n = s.length();
    char x, max;
    for(int i = n-1; i>=0; i--){
        x = s[i];
        if (x>= max){
            max= x; 
            sol+= x;
        }
    }
    for (int i = 0; i<n/2; i++) swap(sol[i], sol[n-i-1]); 
    cout << sol << endl;
}
