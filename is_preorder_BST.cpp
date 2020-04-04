#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, sol=1;
    cin >> t;
    while(t--){
       cin >> n;
       int a[n];
       for(int i=0; i<n; i++){
           cin << a[i];
       }
       stack<int> s;
       root=numeric_limits<int>::min(); 
       for(int i=0; i<n; i++){
           if (a[i]<root) sol=0;
           while (!s.empty() && s.top()<a[i]){
            root=s.pop();
           s.pop();
           }
           s.push_back(a[i]);
       }
       cout << sol;
       sol=1;
    }
}
