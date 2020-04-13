#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s;
    cin >> n;
    int x[n],h[n];
    s=1; //the first can always fall to the left
    for (int i=0; i<n; i++) {cin >> x[i] >> h[i];}
    for (int i=1; i<n; i++) {
        if (h[i]< x[i]-x[i-1]) s++;
        else if (h[i]< x[i+1]-x[i]){
            x[i]+=h[i];
            s++;
        }
    }
    cout << s << endl;
}
