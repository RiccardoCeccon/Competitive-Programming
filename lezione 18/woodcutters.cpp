/* http://codeforces.com/contest/545/problem/C?locale=en

The first tree can always be cut. Then we scan from the left and greedily we cut the tree if there is enough space between it and 
the previous one or between it and the following one; in the second case, we update the position of the tree with the position of its
tip when cut.
Running time and space complexity are O(n).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s;
    cin >> n;
    int x[n],h[n];
    s=1; //the first can always fall to the left
    for (int i=0; i<n; i++) {cin >> x[i] >> h[i];}
    for (int i=1; i<n; i++) {
        if (h[i]< x[i]-x[i-1]) s++;
        else if (h[i]< x[i+1]-x[i]){
            x[i]+=h[i];
            s++;
        }
    }
    cout << s << endl;
}
