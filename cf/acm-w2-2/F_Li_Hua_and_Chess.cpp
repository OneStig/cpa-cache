#include <bits/stdc++.h>

using namespace std;

bool bounds(int x, int y, int n, int m) {
    return !(x < 1 || y < 1 || x > m || y > n);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m; // m on x

        int fsteps;
        cout << "? 1 1" << endl;
        cout.flush();

        cin >> fsteps;

        if (fsteps == 0) {
            cout << "! 1 1" << endl;
            continue;
        }

        // cout << "N: " << n << endl;

        int sx = min(m, 1 + fsteps), sy = min(n, 1 + fsteps);

        cout << "? " << sy << " " << sx << endl;
        cout.flush();

        int ssteps;
        cin >> ssteps;

        if (ssteps == 0) {
            cout << "! " << sy << " " << sx << endl;
            continue;
        }

        int p1x = sx, p1y = sy - ssteps;
        int p2x = sx - ssteps, p2y = sy;

        if (bounds(p1x, p1y, n, m)) {
            if (bounds(p2x, p2y, n, m)) {
                cout << "? " << p1y << " " << p1x << endl;
                cout.flush();

                int ans;
                cin >> ans;

                if (ans == 0) {
                    cout << "! " << p1y << " " << p1x << endl;
                }
                else {
                    cout << "! " << p2y << " " << p2x << endl;
                }
            }
            else {
                cout << "! " << p1y << " " << p1x << endl;
            }
        }
        else {
            cout << "! " << p2y << " " << p2x << endl;
        }
    }
}