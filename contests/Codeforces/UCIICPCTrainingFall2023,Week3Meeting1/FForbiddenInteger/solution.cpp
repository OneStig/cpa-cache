#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k, x;
		cin >> n >> k >> x;

		if (x != 1) {
			cout << "YES " << endl << n << endl;
			for (int i = 0; i < n; i++) {
				if (i != 0) {
					cout << " ";
				}

				cout << 1;
			}
			
			cout << endl;
			continue;
		}

		if (k == 1 || (k == 2 && n % 2 == 1)) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
		cout << n / 2 << endl;

		if (n % 2) {
			for (int i = 0; i < n / 2 - 1; i++) {
				cout << 2 << " ";
			}
			cout << 3;
		} else {
			for (int i = 0; i < n / 2; i++) {
				if (i != 0) {
					cout << " ";
				}

				cout << 2;
			}
		}
		
		cout << endl;
	}
}
