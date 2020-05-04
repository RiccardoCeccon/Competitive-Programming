/* https://www.spoj.com/problems/INVCNT/

We use a bit to solve the problem: we scan the array in decreasing order and we add 1 to the correspondix index in the BIT, and we also
sum up to that index minus one. The total sum is the right result.
Running time is O(n*log(n)) and space complexity is O(n).
*/ 

#include<bits/stdc++.h>
using namespace std;

int64_t BITsum(int64_t BIT[], int64_t ind) { 
    int64_t sum = 0;  
    ind = ind + 1;
    while (ind>0) {
        sum += BIT[ind]; 
        ind -= ind & (-ind); 
    } 
    return sum; 
} 
  
 
void BITadd(int64_t BIT[], int64_t n, int64_t ind, int64_t value) { 
    ind = ind + 1; 
    while (ind <= n) { 
    BIT[ind] += value; 
    ind += ind & (-ind); 
    } 
} 
  
int main() { 
    int64_t t, n, x, sol=0;
    cin >> t;
    while (t--){
        cin >> n;
        vector< pair<int64_t, int64_t>> a;
        a.reserve(n);
        int64_t BIT[n+1]={0};
        for (int64_t i=0; i<n; i++) {
            cin >> x;
            a.push_back(make_pair(x,i));
        }
        sort (a.begin(),a.end());
        for (int64_t i=n-1; i>=0; i--) {
            BITadd(BIT, n, a[i].second, 1);
            sol+=BITsum(BIT, a[i].second-1);
        }
        cout << sol << endl;
        sol=0;
    }
}
