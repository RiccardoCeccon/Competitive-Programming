/* https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

We scan the array from the left: at each step we update the number of jumps needed.
Running time is O(n^2). There is also a O(n) solution but I didn't get it by myself.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    int MAX=10000001;
    while(t--){
        cin >> n;
        int s[n], c[n];
        for (int i=0; i<n; i++) cin >> c[i];
        s[0]=0;
        if (c[0]==0) cout << -1 << endl;
        for (int i=1; i<n; i++){
            s[i]=MAX;
            for (int j=0; j<i; j++){
                if (j+c[j]>=i) s[i]=min(s[i],s[j]+1);
            }
        }
        if (s[n-1]==MAX) cout << -1 << endl;
        else cout << s[n-1] << endl;
    }
} 
