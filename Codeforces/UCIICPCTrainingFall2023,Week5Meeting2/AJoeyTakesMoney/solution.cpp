#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		long long ans = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans *= a[i];
		}

		ans += n - 1;
		ans *= 2022;

		cout << ans << endl;
	}
}
