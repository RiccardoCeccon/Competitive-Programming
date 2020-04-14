#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    string s;
    cin >> N;
    vector<pair<int, string>> p;
    p.reserve(N);
    for(int i=0;i<N;i++) {
        cin >> s >> a;
        p.push_back(make_pair(a, s));
    }
    sort(p.begin(), p.end());
    for(int i=0; i<N; i++) {
        if (p[i].first>i) {
            cout << -1 << endl;
            return 0;    
        }
    }
    vector<int> height;
    for(int i=0; i<N; i++){
        height.insert(height.begin()+i-p[i].first, i);
    }
    int sol[N];
    for(int i=0; i<N; i++){
        sol[height[i]]=10*(i+1);
    }
    for(int i=0; i<N; i++){
        cout << p[i].second << " " << sol[i] << endl;
    }
}
