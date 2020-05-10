/* http://codeforces.com/problemset/problem/52/C 

We implement a segment tree with lazy propagation with minimum property (i.e. the parent is the minimum of the two children).
Running time is O(m*log(n)).
*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 2000000001;
  
//MAX_SIZE= 2*(int)pow(2,ceil(log2(200001)))+1;
int64_t tree[600000] = {};  
int64_t lazy[600000] = {};  


void updateRangeUtil(int si, int ss, int se, int us, int ue, int64_t diff) { 
    if (lazy[si] != 0) { 
        tree[si] += lazy[si]; 
        if (ss != se) { 
            lazy[si*2 + 1] += lazy[si]; 
            lazy[si*2 + 2] += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>ue || se<us) return ; 
    if (ss>=us && se<=ue)  { 
        tree[si] += diff; 
        if (ss != se) { 
            lazy[si*2 + 1] += diff; 
            lazy[si*2 + 2] += diff; 
        } 
        return; 
    }  
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
    tree[si] = min(tree[si*2+1], tree[si*2+2]); 
} 
  

void updateRange(int n, int us, int ue, int64_t diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
int64_t getRMQUtil(int ss, int se, int qs, int qe, int si) { 
    if (lazy[si] != 0) { 
        tree[si] += lazy[si]; 
        if (ss != se) { 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>qe || se<qs)  return MAX; 
    if (ss>=qs && se<=qe) return tree[si]; 
    int mid = (ss + se)/2; 
    return min(getRMQUtil(ss, mid, qs, qe, 2*si+1), getRMQUtil(mid+1, se, qs, qe, 2*si+2)); 
}


int64_t getRMQ(int n, int qs, int qe) { 
    if (qs < 0 || qe > n-1 || qs > qe) { 
        printf("Invalid Input"); 
        return MAX; 
    } 
    return getRMQUtil(0, n-1, qs, qe, 0); 
} 

void constructSTUtil(int64_t arr[], int ss, int se, int si) { 
    if (ss > se) return ; 
    if (ss == se) { 
        tree[si] = arr[ss]; 
        return; 
    } 
    int mid = (ss + se)/2; 
    constructSTUtil(arr, ss, mid, si*2+1); 
    constructSTUtil(arr, mid+1, se, si*2+2); 
    tree[si] = min(tree[si*2 + 1], tree[si*2 + 2]); 
} 
  

void constructST(int64_t arr[], int n) { 
    constructSTUtil(arr, 0, n-1, 0); 
} 
  

 
int main() { 
    int n, m;
    cin >> n;
    int64_t a[n];
    int l=0, r;
    int64_t v;
    for (int i=0; i<n; i++) cin >> a[i];
    constructST(a, n);
    
    cin >> m;
    string input;
    getline(cin, input);
    while(m--){
        getline(cin, input);
        l = stoi(input.substr(0, input.find(' ')));
        input.erase(0, input.find(' ') + 1);
        
        if (input.find(' ')==string::npos){
            r = stoi(input);
            if (r<l) {
                v=min(getRMQ(n, 0, r), getRMQ(n, l, n-1));
                cout << v << endl;
            } else { 
                v=getRMQ(n, l, r);
                cout << v << endl;
            }
        } else {
            r = stoi(input.substr(0, input.find(' ')));
            input.erase(0, input.find(' ') + 1);
            v = stoi(input);
            
            if (r<l) {
                updateRange(n, 0, r, v);
                updateRange(n, l, n-1, v);
            } else { 
                updateRange(n, l, r, v);
            }
        }
    }
    
    return 0; 
} 

