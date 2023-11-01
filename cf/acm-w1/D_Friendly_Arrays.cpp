#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int axor = 0;

        for (int i = 0; i < n; i++) {
            int cura;
            cin >> cura;

            axor = axor ^ cura;
        }

        int ob = 0;

        for (int i = 0; i < m; i++) {
            int curb;
            cin >> curb;

            ob = ob | curb;
        }

        if (n % 2) {
            ob = axor | ob;

            cout << axor << " " << ob << endl;
        }
        else {
            ob = ~ob;
            ob = axor & ob;

            cout << ob << " " << axor << endl;
        }
    }
}