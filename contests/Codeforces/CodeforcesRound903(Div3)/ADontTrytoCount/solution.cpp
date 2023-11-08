#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        string x, s;
        cin >> n >> m >> x >> s;
 
        // if (x == s) {
        //     cout << 0 << endl;
        //     continue;
        // }
 
        while (x.size() <= m + n) {
            x += x;
        }
 
        int test = x.find(s);
 
        if (test != -1) {
            test += m - 1;
            int ans = 0;
            int k = n;
            while (k <= test) {
                k *= 2;
                ans++;
            }
 
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
 
