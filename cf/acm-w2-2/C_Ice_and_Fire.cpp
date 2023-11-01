#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string envs;
        cin >> n >> envs;

        int wins = 1;

        cout << 1;

        for (int x = 3; x <= n; x++) {
            if (envs[x - 2] != envs[x - 3]) {
                wins = x - 1;
            }

            cout << " " << wins;
        }
        
        cout << endl;
    }
}

// 4
// 0 0 1
// 1 2 3 4

// 2: only 1 can win
// 3: only 1 can win
// 4: 1 can no longer win, 2 3 4 can win