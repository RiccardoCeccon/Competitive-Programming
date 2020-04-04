#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, sol=1;
    cin >> t;
    while(t--){
       cin >> n;
       int a[n];
       for(int i=0; i<n; i++){
           cin >> a[i];
       }
       stack<int> s;
       int root=-1001; 
       for(int i=0; i<n; i++){
           if (a[i]<root) sol=0;
           while (!s.empty() && s.top()<a[i]){
            root=s.top();
           s.pop();
           }
           s.push(a[i]);
       }
       cout << sol << endl;
       sol=1;
    }
}
