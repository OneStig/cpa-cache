#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= 6; k++) {
			if (i - k >= 0) {
				dp[i] += dp[i - k];
				dp[i] %= (long long)(1e9 + 7);
			}
		}
	}

	cout << (dp[n] % (long long)(1e9 + 7)) << endl;
}
