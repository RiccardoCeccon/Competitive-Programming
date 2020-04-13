#include <bits/stdc++.h>
using namespace std;


bool isprime(int n){
    if (n==1) return false;
    if (n==2 || n==3 || n==5) return true;
    if (n%2==0) return false;
    for (int i=3; i<=sqrt(n); i+=2){
        if (n%i==0) return false;
    }
    return true;
}


int main(){
    int t, n, a;
    cin >> t;
    while(t--){
        cin >> n;
        int sol=0;
        vector<int> subord[n];
        queue<int> Q;
        for (int i=0; i<n; i++){
            cin >> a;
            if (a==0) Q.push(i); //boss
            else{
                a--;
                subord[a].push_back(i);
               
            }
        }
        //BFS for degree
        int degree[n]={};
        while(!Q.empty()){
            int emp=Q.front();
            Q.pop();
            for (auto j:subord[emp]){
                Q.push(j);
                degree[j]=degree[emp]+1;
            }
        }
        for (int i=0; i<n; i++){
            if(isprime(degree[i]+i+1) && degree[i]!=0) sol++;
        }
        cout << sol << endl;
    }
    return 0;
}
