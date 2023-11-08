#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		if (m == 1) {
			cout << 0 << endl;

			while (n--) {
				cout << 0 << endl;
			}
			
			continue;
		}

		cout << min(m, n + 1) << endl;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j != 0) {	cout << " "; }

				if (m > n || i < m - 1) {
					cout << (i + j) % m;
				}
				else {
					cout << j;
				}
			}
			cout << endl;
		}
	}
}

// 0 1 2
// 2 0 1
// 1 2 0
// 0 1 2
// n + 1 or m, or 1
