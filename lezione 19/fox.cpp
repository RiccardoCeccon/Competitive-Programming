/* http://codeforces.com/problemset/problem/510/C?locale=en

First of all we construct a graph from the information given by the ordering of the words.
Then we perform the topological sort over this graph in order to find a good ordering of the letters.
If there is a cycle we stop the function.
Running time is O(n).
*/


#include <bits/stdc++.h>
using namespace std;

bool DFS_visit(vector<int> adj[], int i, int color[], queue<int> &Q){
    color[i]=1; //gray
    for (auto x: adj[i]){
        if (color[x]==1) return false; //cycle
        if (color[x]==0){
            bool out=DFS_visit(adj, x, color, Q);
            if (!out) return false;
        }
    } 
    color[i]=2; //black
    Q.push(i);
    return true;
}

int main(){
    int n;
    int let, oldlet;
    cin >> n;
    string s, old;
    cin >> old;
    vector<int> adj[26];
    while(--n){
        cin >> s;
        int pos=0;
        while (pos<min(s.length(),old.length()) && s[pos]==old[pos]) pos++;
        if (pos==s.length()) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (pos==old.length()) continue;
        let=s[pos]-'a';
        oldlet=old[pos]-'a';
        adj[let].push_back(oldlet);
        old=s;
    }
    // now we have the graph adj
    
    //for (int i=0; i<26; i++){
       // for (auto x:adj[i]) cout << i << " " << x << endl;
    //}
    
    int color[26]={}; //white
    queue<int> Q;
    bool sol;
    for (int i=0; i<26; i++){
        if (color[i]==0) {
            sol=DFS_visit(adj, i, color, Q);
            if (!sol) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    while(!Q.empty()) {
        char out=Q.front()+'a';
        cout << out;
        Q.pop();
    }
    cout << endl;
    return 0;
}
