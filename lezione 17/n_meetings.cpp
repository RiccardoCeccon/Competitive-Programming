/* https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

We sort the meetings wrt to the finish time, in nondecreasing order. We scan greedily the sorted list and we select an event if 
its beginning time is compatible with the finish time of the last one selected.
Time complexity is O(n*log(n)) due to sorting.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, a;
    cin >> T;
    vector<int> S;
    vector<pair<int,int>> F;
    int fin;
    for (int i=0; i<T; i++) {
        cin >> n;
        S.reserve(n);
        F.reserve(n);
        for (int j=0; j<n; j++) cin >> S[j];
        for (int j=0; j<n; j++) {
            cin >> a;
            F.push_back(make_pair(a,j));
        }
        sort (F.begin(),F.end());
        fin=0;
        for (int j=0; j<n; j++) {
            if (S[F[j].second]>=fin) {cout<< F[j].second+1 << " ";
                fin=F[j].first;
                }
        }
        S.clear();
        F.clear();
        cout << endl;
    }
}
