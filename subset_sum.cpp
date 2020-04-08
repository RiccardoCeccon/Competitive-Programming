/* highly inefficient*/
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
