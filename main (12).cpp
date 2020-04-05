
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n*=2;
    int a[n], count[90]={0}; 
    for (int i=0; i<n; i++) {
        cin >> a[i];
        count[a[i]-10]++;
    }
    int n1=0, n2=0;
    for (int i=0; i<90; i++){
        if (count[i]==1 && n1<=n2) {
            n1++;
            count[i]=-1;
        }
        else if (count[i]==1 && n2<n1) {
            n2++;
            count[i]=-2;
        }
        else if (count[i]>=2) {
            n1++; n2++;
        }
    }
    cout << n1*n2 << endl;
    for (int i=0; i<n; i++) {
        if (count[a[i]-10]==-1) cout << 1 << " ";
        else if (count[a[i]-10]==-2) cout << 2 << " ";
        else {
            cout << count[a[i]-10]%2 + 1 << " ";
            count[a[i]-10]--;
        }
    } 
}