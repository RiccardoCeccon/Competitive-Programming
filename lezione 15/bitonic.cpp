/* https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0

We use the O(log(n)*n) method for the LIS in order to get for every i the length of the LIS from the left and from the right. 
Summing these two quantities minus one, we get the longest bitonic sequence that inverts in i. Taking the maximum over i we get the result.
Running time is O(n*log(n)).
*/

#include <bits/stdc++.h> 
using namespace std;

int CeilIndex(vector<int>& v, int l, int r, int key) {
    while (r-l>1) { 
        int m=l+(r-l)/2; 
        if (v[m] >= key) r = m; 
        else l = m; 
    } 
    return r; 
} 

int main() { 
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        if (n==0) {
            cout << 0;
            continue;
        }
        vector<int> v(n, 0);
        for (int i=0; i<n; i++) cin >> v[i];
        
        int length=1;
        vector<int> ltail(n, 0);
        vector<int> llength(n, 0);
        ltail[0]=v[0];
        llength[0]=1;
        for (int i=1; i<n; i++) { 
            if (v[i]<ltail[0]) ltail[0]=v[i]; 
            else if (v[i]>ltail[length-1]) ltail[length++]=v[i]; 
            else ltail[CeilIndex(ltail, -1, length-1, v[i])]=v[i]; 
            llength[i]=length;
        }
        
        reverse(v.begin(),v.end());
        
        length=1;
        vector<int> rtail(v.size(), 0); 
        vector<int> rlength(v.size(), 0);
        rtail[0]=v[0];
        rlength[0]=1; 
        for (int i=1; i<n; i++) { 
            if (v[i]<rtail[0]) rtail[0]=v[i]; 
            else if (v[i]>rtail[length-1]) rtail[length++]=v[i]; 
            else rtail[CeilIndex(rtail, -1, length-1, v[i])]=v[i]; 
            rlength[i]=length;
        }
        
        reverse(rlength.begin(),rlength.end());
        for (int i=0; i< n; i++) {
            rlength[i]=rlength[i]+llength[i]-1;
        }
        cout << *max_element(rlength.begin(),rlength.end()) << endl;
    }
} 
