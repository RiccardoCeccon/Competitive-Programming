/* http://codeforces.com/problemset/problem/196/A?locale=en

We keep track of the running maximum from the right and greedily every time we find a letter greater or equal than it we 
keep the letter into the subsequence. 
Running time is O(n) and space complexity is O(n).
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, sol="";
    cin >> s;
    int n;
    n = s.length();
    char x, max='0';
    for(int i = n-1; i>=0; i--){
        x = s[i];
        if (x>= max){
            max= x; 
            sol+= x;
        }
    }
    reverse(sol.begin(),sol.end());
    cout << sol << endl;
}
