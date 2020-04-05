#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;
    k=k-1;
    int64_t a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int64_t i=k/n;
    int64_t l;
    for (l=0; l<n; l++){
        if(a[l]==a[i]) break;
    }
    int64_t r;
    for (r=0; r<n-l; r++){
        if (a[l+r]!=a[i]) break;
    }
    cout << a[i] << " " << a[(k - l*n)/r] << endl;
}
