#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> lastpos(101);
		vector<int> occ(101);
		vector<int> a(n + 1);

		int dups = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			
			lastpos[a[i]] = i;
			occ[a[i]]++;
		}

		vector<int> b(n + 1, 1);
		int found = 2;
		for (int i = 0; i < 101; i++) {
			if (occ[i] > 1) {
				dups++;

				if (found < 4) {
					b[lastpos[i]] = found;
					found++;
				}
			}
		}

		if (dups < 2) {
			cout << -1 << endl;
			continue;
		}


		for (int i = 1; i <= n; i++) {
			if (i != 1) {
				cout << " ";
			}
			cout << b[i];
		}
		cout << endl;
	}
}
