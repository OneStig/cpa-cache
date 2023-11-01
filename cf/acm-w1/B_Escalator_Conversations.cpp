#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k, h;
        cin >> n >> m >> k >> h;

        int ppl[50];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> ppl[i];

            if (h == ppl[i]) {
                continue;
            }

            int diff = abs(ppl[i] - h);

            if (diff % k) {
                continue;
            }

            if (diff / k <= m - 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}