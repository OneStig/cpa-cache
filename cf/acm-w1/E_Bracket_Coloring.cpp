#include <bits/stdc++.h>

using namespace std;

bool rbs(string s, int l) {
    int le = 0;
    
    for (int i = 0; i < l; i++) {
        if (s[i] == '(') {
            le++;
        } else {
            le--;
        }

        if (le < 0) {
            le = INT_MIN;
            break;
        }
    }

    return le == 0;
}

int main() { 
    int t;
    cin >> t;
    while (t--) {
        int n;
        string brack;
        cin >> n >> brack;

        int open = 0, close = 0;

        for (int i = 0; i < n; i++) {
            if (brack[i] == '(') {
                open++;
            } else {
                close++;
            }
        }

        if (open != close) {
            cout << -1 << endl;
            continue;
        }


    }
}


// ( ( ( ) ) ) ) (
// 1 1 1 2 2 2 2 1
// 1 2 3 2 1 0 -1 0


// )( )(

// ((())))(
// 