#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    string s;
    cin >> N;
    vector<pair<int, string>> p;
    people.reserve(N);
    for(int i=0;i<N;i++) {
        cin >> s >> a;
        p[i]=make_pair(a, s);
    }
    sort(p.begin(), p.end())
    for(int i=0;i<N;i++) {
        if (p[i].first>i) cout << -1 << endl;
        return 0;
    }
    vector<int> height;
    for (i=0; i<N; i++){
        height.insert(height.begin()+i-p[i].first, i);
    }
    int sol[n];
    for (i=0; i<N; i++){
        sol[height[i]]=10*i+1
    }
}
