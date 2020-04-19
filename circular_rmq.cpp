#include <bits/stdc++.h>
using namespace std;
#define MIN -100000;
#define MAX 100000;

  
//const MAX_SIZE= 2*(int)pow(2,ceil(log2(200001)))+1;
int tree[300000] = {};  
int lazy[300000] = {};  


void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) { 
    if (lazy[si] != 0) { 
        tree[si] += lazy[si]; 
        if (ss != se) { 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>ue || se<us) return ; 
    if (ss>=us && se<=ue)  { 
        tree[si] += diff; 
        if (ss != se) { 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    }  
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
    tree[si] = min(tree[si*2+1], tree[si*2+2]); 
} 
  

void updateRange(int n, int us, int ue, int diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
int getRMQUtil(int ss, int se, int qs, int qe, int si) { 
    if (lazy[si] != 0) { 
        tree[si] += (se-ss+1)*lazy[si]; 
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


int getRMQ(int n, int qs, int qe) { 
    if (qs < 0 || qe > n-1 || qs > qe) { 
        printf("Invalid Input"); 
        return MAX; 
    } 
    return getRMQUtil(0, n-1, qs, qe, 0); 
} 

void constructSTUtil(int arr[], int ss, int se, int si) { 
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
  

void constructST(int arr[], int n) { 
    constructSTUtil(arr, 0, n-1, 0); 
} 
  

 
int main() { 
    int n, m;
    cin >> n;
    int a[n];
    int l=0, r, v;
    for (int i=0; i<n; i++) cin >> a[i];
    constructST(a, n);
    cin >> m;
    string input;
    for (int i=0; i<m; i++){
        cin >> l >> r >> v;
        updateRange(n, l, r, v);
    
        cin >> l >> r;
        if (r<l) {
            v=min(getRMQ(n, 0, r), getRMQ(n, l, n-1));
            cout << v << endl;
        } else { 
            v=getRMQ(n, l, r);
            cout << v << endl;
        }
    }
    return 0; 
} 
  
