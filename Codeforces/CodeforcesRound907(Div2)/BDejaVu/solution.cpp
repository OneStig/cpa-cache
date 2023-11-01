#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		vector<long long> a(n);
		vector<long long> x(q);
		
		vector<long long> sums(35);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<long long> rx(31);
		long long tmp = 2;
		for (int i = 1; i <= 30; i++) {
			rx[i] = tmp;
			tmp *= 2;
		}

		for (int i = 0; i < q; i++) {
			cin >> x[i];
			x[i] = rx[x[i]];
		}

		long long cur = 2;
		long long divisibility;
		for (int i = 1; i <= 30; i++) {
			sums[i] = cur;
			for (int j = 0; j < q; j++) {
				if (sums[i] % x[j] == 0) {
					sums[i] += x[j] / 2;
				} 
			}
			sums[i] -= cur;	
			cur *= 2;
		}

		cur /= 2;

		for (int i = 0; i < n; i++) {
			long long comput = cur;
			int ans = 30;

			while (ans > 0) {
				if (a[i] % comput == 0) {
					break;
				}

				comput /= 2;
				ans--;
			}

			if (i != 0) {
				cout << " ";
			}

			cout << a[i] + sums[ans];
		}

		cout << endl;
	}
}
