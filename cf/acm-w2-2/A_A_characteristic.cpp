#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        int pos = n;
        int negs = 0;

        bool solve = 0;

        while (negs <= n / 2) {
            long long cur = (pos * (pos - 1)) / 2 + (negs * (negs - 1)) / 2;
            if (cur == k) {
                solve = 1;
                break;
            }

            negs++;
            pos--;
        }

        if (solve) {
            cout << "YES" << endl;
            while (pos--) {
                cout << 1 << " ";
            }

            while (negs--) {
                cout << -1;

                if (negs > 0) {
                    cout << " ";
                }
            }

            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}


// 1 1 1 1 1 4 + 3 + 2 + 1 : 10
// 1 1 1 1 -1 3 + 2 + 1    : 5
// 1 1 1 -1 -1 2 + 1, 1    : 4
// 1 1 -1 -1 -1 , 