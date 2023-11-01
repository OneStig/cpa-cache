#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);

		long long sum = 0;
		multiset<int> diffs;

		for (int i = 0; i < n; i++) {
			cin >> a[i];

			if (i > 0) {
				int cur = abs(a[i] - a[i - 1]);
				sum += cur;
				diffs.insert(cur);
			}
		}

		auto it = diffs.rbegin();

		for (int i = 0; i < k - 1; i++, it++) {
			sum -= *it;
		}

		cout << sum << endl;
	}
}
