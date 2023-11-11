#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> b(m);
		multiset<int> a;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			a.insert(tmp);
		}

		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		for (int i = 0; i < m; i++) {
			int cur = *(a.begin());
			a.erase(a.begin());
			a.insert(b[i]);
		}

		long long ans = 0;
		for (auto it = a.begin(); it != a.end(); it++) {
			ans += *it;
		}

		cout << ans << endl;
	}
}
