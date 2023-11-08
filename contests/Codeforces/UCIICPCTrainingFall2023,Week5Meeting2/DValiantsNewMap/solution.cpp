#include <bits/stdc++.h>
#include <memory>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;

		vector<vector<int> > build(n);
		vector<vector<int> > dp_sz(n);
		vector<vector<int> > dp(n);

		for (int i = 0; i < n; i++) {
			build[i].resize(m);
			dp[i].resize(m);

			for (int j = 0; j < m; j++) {
				cin >> build[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			dp_sz[i][0] = 1;
			dp[i][0] = build[i][0];
		}

		for (int i = 0; i < m; i++) {
			dp_sz[0][i] = 1;
			dp[0][i] = build[0][i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[]:while
			}
		}
	}
}
