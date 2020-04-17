/* https://codeforces.com/problemset/problem/276/C?locale=en

We sort the input array and the array that counts the number of queries that cover every index from 0 to n-1.
We then couple higher numbers with "higher" indices, from the point of view of this sorting.
Running time is O(n*logn) due to the sorting procedure, space complexity is O(n).
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int l, r, sol=0;
    int a[n], p[n+1]={0};
    long long int s[n];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<q; i++) {
    cin >> l >> r;
    p[l-1]+=1;
    p[r]+=-1;
    }
    s[0]=p[0];
    for (int i=1; i<n; i++) {
    s[i]=s[i-1]+p[i];
    }
    
    sort(s, s+n);
    sort(a, a+n);
    for (int i=0; i<n; i++) {
    sol+=a[i]*s[i];
    }
    cout << sol << endl;
}
