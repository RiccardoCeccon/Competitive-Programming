/* https://codeforces.com/problemset/problem/313/B

We define the vector such that b[i]=b[i-1] iff s[i]=s[i-1]. Its differences are the solutions to the problem.
Space and time complexity are O(n).
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len=s.length();
    int b[len];
    
    b[0]=0;
    while(len--) {
        if (s[i-1]==s[i]) b[i]=b[i-1]+1;
        else b[i]=b[i-1];
    }
    
    int m, l, r;
    cin >> m;
    while(m--) {
        cin >> l >> r;
        int s=b[r-1]-b[l-1];
        cout << s << " ";
    }
}
