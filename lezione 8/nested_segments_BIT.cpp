/* https://codeforces.com/problemset/problem/652/D?locale=en

We sort the vector of left ends and we convert the right ends with their position in the sorted array of right ends.
We scan the l vector in decreasing order and we add 1 to the position r. We sum from 0 to r-1 to get the number of nested segments.
Running time is O(n*log(n)) and space complexity is O(n).
*/

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
    for (int i=0; i<n; i++) arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;  
} 
  

int main(){
    int64_t n;
    cin >> n;
    int64_t a, b;
    vector<pair<int64_t,int>> l;
    int64_t r[n];
    l.reserve(n);
    int64_t sol[n];
    int64_t BIT[n+2]={0};
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        l.push_back(make_pair(a,i));
        r[i]=b;
    }
    
    sort(l.begin(),l.end());
    convert(r, n);
    
    for (int i=n-1; i>=0; i--){
        a=r[l[i].second];
        BITadd(BIT, n+1, a, 1);
        sol[l[i].second]=BITsum(BIT, a-1);
    }
    
    for (int i=0; i<n; i++){
        cout << sol[i] << endl;
    }
    
}
