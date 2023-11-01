#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool found = 0;
        for (int a = 1; a <= 10; a++) {
            for (int b = a + 1; b <= 10; b++) {
                int c = n - a - b;

                if (c > b && a % 3 != 0 && b % 3 != 0 && c % 3 != 0) {
                    cout << "YES" << endl << a << " " << b << " " << c << endl;
                    found = 1;
                    break;
                }
            }

            if (found) {
                break;
            }
        }

        if (!found) {
            cout << "NO" << endl;
        }
    }
}