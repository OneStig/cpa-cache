#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);

		long long monst = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			monst += a[i];
		}

		sort(a.rbegin(), a.rend());

		long long attacks = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				break;
			}

			if (a[i] <= monst - a[i]) {
				attacks += 1 + a[i];
				long long sum = 0;
				for (int j = n - 1; j >= 0; j--) {
					if (sum + a[j] <= a[i]) {
						sum += a[j];
						monst -= a[j];
						a[j] = 0;
						n--;
					}
					else {
						long long used = a[i] - sum;
						a[j] -= used;
						monst -= used;
						break;
					}
				}
				monst -= a[i];
				a[i] = 0;
			}
			else {
				long long cc = monst - a[i];
				a[i] -= cc;
				cc += a[i] / 2;
				a[i] -= 2 * (a[i] / 2);
				if (cc > 0) {
					attacks += cc + 1;
				}

				attacks += a[i];
				break;
			}
		}

		cout << attacks << endl;
	}
}
