/*https://codeforces.com/problemset/problem/37/A?locale=en

This algorithm solves the Towers Problem. For every natural number we count the number of blocks of that length.
Every time a new number appears, we count it, and we also keep track of the maximum.
Time complexity is O(n) because we perform only one loop, space complexity is O(1).
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, a, c=0, m=0;
    cin >> n;
    int num[1001]={};
    while(n--) {
        cin >> a;
        if(num[a]==0) c++;
        num[a]++;
        if(num[a]>m) m++;
    }
    cout << m << " " << c << endl;
}
