#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    string s;
    cin >> N;
    vector<pair<int, string>> p;
    people.reserve(N);
    for(int i=0;i<N;i++) {
        cin >> s >> x;
        p[i]=make_pair(x, s);
    }
    sort(p.begin(), p.end())
    for(int i=0;i<N;i++) {
        if (p[i].first>i) cout << -1 << endl;
        return 0;
    }
    
}
