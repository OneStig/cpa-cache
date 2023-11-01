#include <bits/stdc++.h>

using namespace std;

int dp[105];
int dp_rate[105];

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> courses(n);

	for (int i = 0; i < n; i++) {
		cin >> courses[i];
	}

	memset(dp, 0, sizeof(dp));
	memset(dp, 0, sizeof(dp));

	dp[0] = courses[0];
	dp_rate[0] = m;

	for (int i = 1; i < n; i++) {
		int s0 = min(dp_rate[i - 1] * 2 / 3, dp[i - 1]);

		int s1 = 0;

		if (i > 1) {
			s1 = min(dp_rate[i - 2], dp[i - 2]);
		}

		int s2 = 0;
		if (i > 2) {
			s2 = min(m, dp[i - 3]);
		}

		int max_rate = max(s0, max(s1, s2));

		dp[i] = courses[i] + max(s0, max(s1, s2));
		dp_rate[i] = max_rate;
	}

	int mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		mx = max(mx, dp_rate[i]);
	}

	cout << mx << endl;
}
