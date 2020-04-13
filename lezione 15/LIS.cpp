/* I've decided to present the solution in O(n^2) time, and to use the O(nlog(n)) time one in the solution of the Bitonic Subsequence  
problem, because it wasn't the one I had thought about.*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        int l[n];
        l[0] = 1;    
        for (int i=1; i<n; i++){
            l[i] = 1; 
            for (int j=0; j<i; j++){
                if (a[i]>a[j] && l[i]<l[j]+1) l[i]=l[j]+1;  
            } 
        }
        cout << *max_element(l, l+n) << endl;
    }
    return 0;
}

