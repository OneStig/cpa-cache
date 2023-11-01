#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int mx = INT_MIN;
        long long sums[2];
        memset(sums, 0, sizeof(sums));

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            mx = max(mx, a);
            sums[i % 2] += max(0, a);
        }

        if (!sums[0] && !sums[1]) {
            cout << mx << endl;
        }
        else {
            cout << max(sums[0], sums[1]) << endl;
        }
    }
}