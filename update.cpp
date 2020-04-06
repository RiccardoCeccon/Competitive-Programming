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
    int t, n, u, q, ind;
    cin >> t;
    while (t--){
        cin >> n >> u;
        int64_t BIT[n+1]={0};
        int l, r , val;
        for (int i=0; i<u; i++) {
            cin >> l >> r >> val;
            BITadd(BIT, n, r+1, -val);
            BITadd(BIT, n, l, val);
        }
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> ind;
            cout << BITsum(BIT, ind);
        }
    }
    
}
