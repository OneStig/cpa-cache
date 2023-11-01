#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string grid[n];

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        long long ans = 0;

        for (int y = 0; y < n / 2; y++) {
            for (int x = 0; x < n / 2; x++) {
                char mx = grid[y][x];

                int cx = x, cy = y;
                for (int i = 0; i < 4; i++) {
                    // cout << cx << " " << cy << " " << grid[cy][cx] << " ";
                    mx = max(mx, grid[cy][cx]);
                    int tcx = cx;
                    cx = n - cy - 1;       
                    cy = tcx; 
                }

                for (int i = 0; i < 4; i++) {
                    ans += mx - grid[cy][cx];

                    int tcx = cx;
                    cx = n - cy - 1;
                    cy = tcx;
                }
                
                // cout << endl;
            }
        }

        cout << ans << endl;
    }
}


// bbaa
// abba
// aaba
// abba

// 1

