#include<bits/stdc++.h>
using namespace std;

int64_t BITsum(int64_t BIT[], int ind) { 
    int64_t sum = 0;  
    ind = ind + 1;
    while (ind>0) {
        sum += BIT[ind]; 
        ind -= ind & (-ind); 
    } 
    return sum; 
} 
  
 
void BITadd(int64_t BIT[], int n, int ind, int value) { 
    ind = ind + 1; 
    while (ind <= n) { 
    BIT[ind] += value; 
    ind += ind & (-ind); 
    } 
} 
  
int main() { 
    int t, n, x, sol=0;
    cin >> t;
    while (t--){
        cin >> n;
        vector<pair<int,int>> a;
        a.reserve(n);
        int64_t BIT[n+1]={0};
        for (int i=0; i<n; i++) {
            cin >> x;
            a.push_back(make_pair(x,i));
        }
        sort (a.begin(),a.end());
        for (int i=n-1; i>=0; i--) {
            BITadd(BIT, n, a[i].second, 1);
            sol+=BITsum(BIT, a[i].second-1);
        }
        cout << sol << endl;
        sol=0;
    }
    
}
