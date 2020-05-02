/* https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

First we compute s, the half of the sum of all the entries of the vector. Then we use dynamic programming to see if with the elements 
up to the i-th we can get the sum equal to j. the answer is a[i][s].
Running time is O(n*s).
*/

#include <bits/stdc++.h>
using namespace std;

int main (){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++) cin >> a[i];
        int s=accumulate (a, a+n, 0);
        if(s%2==1) {
            cout << "NO" << endl;
            continue;
        }
        s/=2;
        int sol[n+1][s+1];
        for (int i=0; i<=n; i++){
            for (int j=0; j<=s; j++){
                if (j==0) sol[i][j]=1;
                else if (i==0) sol[i][j]=0;
                else if(sol[i-1][j]==1 || sol[i-1][j-a[i-1]]==1) sol[i][j]=1;
                else sol[i][j]=0;
            }
        }
        if(sol[n][s]==1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
