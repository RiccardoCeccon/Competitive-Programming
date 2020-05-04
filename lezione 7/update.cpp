/* https://www.spoj.com/problems/UPDATEIT/
 
Per risolvere il problema, usiamo un BIT per aggiungere il valore val all'indice l e toglierlo all'indice r+1. 
Le risposte sono date dalle somme sul BIT fino all'indice richiesto.
Il tempo di calcolo è O(log(n)*(u+q)), lo spazio occupato è O(n).
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
    int64_t t, n, u, q, ind;
    cin >> t;
    while (t--){
        cin >> n >> u;
        int64_t BIT[n+1]={0};
        int64_t l, r , val;
        for (int i=0; i<u; i++) {
            cin >> l >> r >> val;
            BITadd(BIT, n, r+1, -val);
            BITadd(BIT, n, l, val);
        }
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> ind;
            cout << BITsum(BIT, ind) << endl;
        }
    }
    
}
