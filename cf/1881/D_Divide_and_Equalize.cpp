#include <bits/stdc++.h>

using namespace std;

int sp[1000001];

void precompute() {
    memset(sp, 0, sizeof(sp));

    for (int p = 2; p <= 1000001; p++) {
        if (!sp[p]) {
            sp[p] = p;

            for (int k = 2 * p; k <= 1000001; k += p) {
                if (sp[k] == 0) {
                    sp[k] = p;
                }
            }
        }
    }
}

int main() {
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> primes;
        unordered_map<int, int> prime_freq;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            while (a > 1) {
                if (prime_freq[sp[a]] == 0) {
                    primes.push_back(sp[a]);
                }

                prime_freq[sp[a]]++;
                a = a / sp[a];
            }
        }

        bool f = 0;

        for (int i = 0; i < primes.size(); i++) {
            if (prime_freq[primes[i]] % n) {
                f = 1;
                break;
            }
        }

        if (f) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}

// sieve of eratosthenes
// 100 2 50 10 1
// 2 2 5 5 2, 2, 5, 5, 2, 5