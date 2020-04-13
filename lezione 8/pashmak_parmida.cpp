#include <bits/stdc++.h>
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

void convert(int64_t arr[], int n) { 
    int64_t temp[n]; 
    for (int i=0; i<n; i++) 
        temp[i] = arr[i]; 
    sort(temp, temp+n); 
    for (int i=0; i<n; i++) arr[i] = lower_bound(temp, temp+n, arr[i]) - temp ;  
} 
  

int main(){
    int64_t n, sol=0;
    cin >> n;
    int64_t a[n];
    int64_t l[n], r[n], count[n]={0}, count2[n]={0};
    for (int i=0; i<n; i++) cin >> a[i];
    convert(a, n);
    for (int i=0; i<n; i++) {
        l[i]=count[a[i]]++;
        r[n-1-i]=count2[a[n-1-i]]++;
    }
    int64_t BIT[n+1]={0};
    for(int i=0; i<n; i++) {
        sol += i - BITsum(BIT, r[i]);
        BITadd(BIT, n, l[i], 1);
    }
    cout << sol << endl;
}
