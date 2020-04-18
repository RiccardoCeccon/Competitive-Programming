/* https://codeforces.com/contest/86/problem/D

We use Mo's Algorithm to solve the problem. The significant part consists in the add and rem functions.
We use a counter to keep track of all the Ks and we use the fact that Ks^2-(Ks-1)^2=2*Ks-1 to perform the add/rem procedure.
Time complexity is O((n+m)*sqrt(n)+m*log(m)), space complexity is O(n+m), where m is the max of the array elements.
*/


#include <bits/stdc++.h>
using namespace std;

void add(int a[], int count[], int ind, unsigned long long& sol){
    sol+=a[ind]*(2*count[a[ind]]+1);
    count[a[ind]]++;
}

void rem(int a[], int count[], int ind, unsigned long long& sol){
    sol-=a[ind]*(2*count[a[ind]]-1);
    count[a[ind]]--;
}


int main()
{
    int n, t, sn, b, l, r;
    cin >> n >> t;
    double s=sqrt(n);
    sn=ceil(s);
    int a[n+1]={};
    vector<tuple<int, int, int>> buck[sn+1];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<t; i++) {
        cin >> l >> r;
        b = floor(l/s);
        l--;
        r--;
        buck[b].push_back(make_tuple(r, l, i));
    }
    
    for(int i=0; i<=sn; i++){
        sort(buck[i].begin(), buck[i].end());
    }
    
    int m=*max_element(a, a+n);
    int count[m+1]={};
    int cur_l=0, cur_r=0;
    count[a[0]]++;
    unsigned long long sol = a[0];
    unsigned long long ans[t]={};
    
    
    for (int i=0; i<=sn; i++) {
        for(auto b:buck[i]){ 
            r=get<0>(b); 
            l=get<1>(b); 
            while (cur_l < l){
                rem(a, count, cur_l, sol);
                cur_l++;
            }
            while (cur_l > l){
                cur_l--;
                add(a, count, cur_l, sol);
            }
            while (cur_r < r){
                cur_r++;
                add(a, count, cur_r, sol);
            }
            while (cur_r > r){
                rem(a, count, cur_r, sol);
                cur_r--;
            }
            
            ans[get<2>(b)]=sol;
        }
    }
    for (int i=0; i<t; i++){cout << ans[i] << endl;}
    
}

