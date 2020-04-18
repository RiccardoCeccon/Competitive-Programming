/* https://codeforces.com/problemset/problem/459/D?locale=en

We perform the same algorithm as with the BIT, but we sum between indices and add values thanks to a segment tree.
The codes for the segment tree are taken from the Geeks4Geeks tutorial.
As before, we scan l in decreasing order, we add 1 to the position r and we sum from 0 to r-1.
Running time is O(n*log(n)) and space complexity is O(n).
*/


#include <bits/stdc++.h> 
using namespace std; 

int getMid(int s, int e) { return s + (e -s)/2; }  
  

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)  {  
    if (qs <= ss && qe >= se) return st[si];  
    if (se < qs || ss > qe)  return 0;  
    int mid = getMid(ss, se);  
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +  
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);  
}  
  

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)  {  
    if (i < ss || i > se) return;  
    st[si] = st[si] + diff;  
    if (se != ss)  {  
        int mid = getMid(ss, se);  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}  

void updateValue(int arr[], int *st, int n, int i, int diff)  {   
    if (i < 0 || i > n-1)  {  
        return;  
    }  
    arr[i] += diff;  
    updateValueUtil(st, 0, n-1, i, diff, 0);  
}  
  

int getSum(int *st, int n, int qs, int qe)  {
    if (qs < 0 || qe > n-1 || qs > qe)  {
        return -1;  
    }  
    return getSumUtil(st, 0, n-1, qs, qe, 0);  
}  

int constructSTUtil(int arr[], int ss, int se, int *st, int si)  {  
    if (ss == se) {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
    int mid = getMid(ss, se);  
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +  
            constructSTUtil(arr, mid+1, se, st, si*2+2);  
    return st[si];  
}  
  

int *constructST(int arr[], int n)  {   
    int x = (int)(ceil(log2(n)));  
    int max_size = 2*(int)pow(2, x) - 1;  
    int *st = new int[max_size];  
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;  
}  

void convert(int64_t arr[], int n) { 
    int64_t temp[n]; 
    for (int i=0; i<n; i++) 
        temp[i] = arr[i]; 
    sort(temp, temp+n); 
    for (int i=0; i<n; i++) arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;  
} 

int main()  { 
    int64_t n;
    cin >> n;
    int64_t a, b;
    vector<pair<int64_t,int>> l;
    int64_t r[n];
    l.reserve(n);
    int64_t sol[n];
    int arr[n]={};
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        l.push_back(make_pair(a,i));
        r[i]=b;
    }
    sort(l.begin(),l.end());
    convert(r, n);
    int* st=constructST(arr, n);
    for (int i=n-1; i>=0; i--){
        a=r[l[i].second];
        updateValue(arr, st, n, a, 1); 
        sol[l[i].second]=getSum(st, n, 0, a-1);
    }
    
    for (int i=0; i<n; i++){
        cout << sol[i] << endl;
    }
}  
