#include <bits/stdc++.h>
using namespace std;

void add(int a[], int count[], int ind, int& sol){
    sol+=a[ind]*(2*count[a[ind]]+1);
    count[a[ind]]++;
}

void rem(int a[], int count[], int ind, int& sol){
    sol-=a[ind]*(2*count[a[ind]]-1);
    count[a[ind]]--;
}


int main()
{
    int n, t, sn, b, l, r;
    cin >> n >> t;
    double s=sqrt(n);
    sn=ceil(s);
    int a[n]={};
    vector<pair<int, int>> buck[sn];
    for (int i=0; i<n; i++) cin >> a[i+1];
    for (int i=0; i<t; i++) {
        cin >> l >> r;
        l--;
        b = floor(l/s);
        buck[b].push_back(make_pair(r, l));
    }
    
    for(int i=0; i<sn; i++){
        sort(buck[i].begin(), buck[i].end());
    }
    
    int m=*max_element(a, a+n);
    int count[m+1]={};
    int cur_l=0, cur_r=0;
    int sol=0;
    
    
    for (int i=0; i<sn; i++) {
        for(auto b:buck[i]){ 
            r=b.first;
            l=b.second;
            
            while (cur_l < l){
                cur_l++;
                rem(a, count, cur_l, sol);
            }
            while (cur_l > l){
                add(a, count, cur_l, sol);
                cur_l--;
            }
            while (cur_r < r){
                cur_r++;
                add(a, count, cur_r, sol);
            }
            while (cur_r > r){
                rem(a, count, cur_l, sol);
                cur_r--;
            }
            
            cout << sol << endl;
        }
    }
    
}
