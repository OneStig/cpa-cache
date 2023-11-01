#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int nums[50];
        int mx = 0;
        bool fail = 0;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            if (i > 0) {
                if (nums[i] < nums[i - 1]) {
                    mx = max(mx, nums[i - 1]);
                    fail = 1;
                }
            }
        }

        cout << (fail ? mx : 0) << endl;
    }
}
