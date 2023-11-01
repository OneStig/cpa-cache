#include <bits/stdc++.h>

using namespace std;

int dp[104];
int dp_rate[104];

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> courses(n + 2);

	for (int i = 0; i < n; i++) {
		cin >> courses[i + 2];
	}

	memset(dp, 0, sizeof(dp));
	memset(dp_rate, 0, sizeof(dp_rate));

	dp[2] = courses[2];
	dp_rate[2] = m;
	dp_rate[1] = m;
	dp_rate[0] = m;

	for (int i = 3; i < n + 2; i++) {
		pair<int, int> a = make_pair(dp[i - 1] + min(dp_rate[i - 1] * 2 / 3, courses[i]), dp_rate[i - 1] * 2 / 3);

		pair<int, int> b = make_pair(dp[i - 2] + min(dp_rate[i - 2], courses[i]), dp_rate[i - 2]);

		pair<int, int> c = make_pair(dp[i - 3] + min(m, courses[i]), m);

		pair<int, int> d = make_pair(dp[i - 3] + min(dp_rate[i - 3], courses[i - 1]) + min(dp_rate[i - 3] * 2 / 3, courses[i]), dp_rate[i - 3] * 2 / 3);

		pair<int, int> best = max(a, max(b, max(c, d)));

		dp[i] = best.first; 
		dp_rate[i] = best.second;
	}

	int ans = INT_MIN;

	for (int i = 0; i < n + 2; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
