#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, l1, l2;
    string s1, s2;
    cin >> t;
    while(t--) {
        cin >> l1 >> l2 >> s1 >> s2;
        int a[l1+1][l2+1];
        for (int i=0; i<=l1; i++){
            for (int j=0; j<=l2; j++){
                if (i==0 || j==0) a[i][j]=0;
                else if (s1[i]==s2[j]) a[i][j]=a[i-1][j-1]+1;
                else a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
        cout << a[l1][l2] << endl;
    }
}
