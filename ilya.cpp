#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int l[n], r[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
    }
    
    if (s[0]==s[1]) b[0]=1;
    else b[0]=0;
    
    for (int i=1; i<n-1; i++) {
        if (s[i]==s[i+1]) b[i]=b[i-1]+1;
        else b[i]=b[i-1];
    }
    
    for (int i=0; i<n; i++) {
        int s=b[r[i]-2]-b[l[i]-2];
        cout << s << " ";
    }
}
