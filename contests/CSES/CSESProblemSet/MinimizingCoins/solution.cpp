#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> coins(n);
	
	fill_n(dp, x + 1, INT_MAX);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		dp[coins[i]] = 1;
	}

	for (int i = 1; i <= x; i++) {
		if (dp[i] != INT_MAX) {
			for (int j = 0; j < coins.size(); j++) {
				if (i + coins[j] <= x) {
					dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
				}
			}
		}
	}

	cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}
