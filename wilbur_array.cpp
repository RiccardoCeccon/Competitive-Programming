#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, b, prev;
    cin >> n;
    cin >> s;
    prev=s;
    for (int i=1; i<n; i++) {cin >> b;
        s += b-prev;
        prev = b;
    }
    cout >> s >> endl;
}
