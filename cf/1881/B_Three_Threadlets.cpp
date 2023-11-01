#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long g = gcd(gcd(a, b), c);

        if ((a / g + b / g + c / g - 3) <= 3) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}