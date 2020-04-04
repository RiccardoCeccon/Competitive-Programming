#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n, len=s.length();
    cin >> n;
    int l, r, b[n];
    
    b[0]=0;
    
    for (int i=1; i<len; i++) {
        if (s[i-1]==s[i]) b[i]=b[i-1]+1;
        else b[i]=b[i-1];
    }
    
    for (int i=0; i<n; i++) {
        cin << l << r;
        int s=b[r-1]-b[l-1];
        cout << s << " ";
    }
}
