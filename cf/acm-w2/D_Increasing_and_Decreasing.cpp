#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;

        long long sumdiff = (n * (n - 1)) / 2;

        if (y - sumdiff < x) {
            cout << -1 << endl;
            continue;
        }

        cout << x << " ";

        vector<int> nums;
        int cur = y;

        for (int i = 0; i < n - 1; i++) {
            cur -= i;
            nums.push_back(cur);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            cout << nums[i];

            if (i > 0) {
                cout << " ";
            }
        }

        cout << endl;
    }
}