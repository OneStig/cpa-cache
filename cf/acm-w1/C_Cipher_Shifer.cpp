#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string cur;

        cin >> n >> cur;

        char startchar = cur[0];
        string ans = "";

        for (int i = 1; i < n; i++) {
            if (cur[i] == startchar) {
                ans += startchar;
                startchar = 0;
            } else if (startchar == 0) {
                startchar = cur[i];
            }
        }

        cout << ans << endl;
    }
}