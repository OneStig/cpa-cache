#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
        }
        else if (n == 2) {
            cout << "2 1" << endl;
        }
        else {
            int c = 4;

            cout << 2;

            for (int i = 1; i < n - 1; i++) {
                if (i == n / 2) {
                    cout << " 1";
                }
                else {
                    cout << " " << c++;
                }
            }

            cout << " 3" << endl;
        }
    }
}