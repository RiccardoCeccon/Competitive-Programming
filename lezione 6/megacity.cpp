/* https://codeforces.com/problemset/problem/424/B?locale=en

We sort cities by distance and include them until we get the desired number of citizens.
Running time is O(n*log(n)) due to sorting, and space complexity is O(n). 
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int x, y, k;
    vector<pair<float,int>> r;
    s=1000000-s;
    r.reserve(n);
    for (int i=0; i<n; i++) {
        cin >> x >> y >> k;
        r.push_back(make_pair(sqrt(x*x+y*y),k));
    }
    sort (r.begin(),r.end());
    int i=0;
    while (s>0 && i<n){
        s-=r[i++].second;
    }
    if (s>0){
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(7) << r[i-1].first << endl;
    return 0;
}

