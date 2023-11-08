#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		vector<int> b(m);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(b.rbegin(), b.rend());

		int bp = 0;

		bool f = 0;
		for (int i = 0; i < n; i++) {
			while (bp < m && b[bp] >= a[i]) {
				if (f) {
					cout << " ";
				}
				f = 1;
				cout << b[bp];
				bp++;
			}
			if (f) {
				cout << " ";
			}
			f = 1;
			cout << a[i];
		}

		while (bp < m) {
			cout << " " << b[bp];
			bp++;
		}

		cout << endl;
	}
}
