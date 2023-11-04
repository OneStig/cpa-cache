#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		vector<pair<int, int> > dp(n);
		vector<long long> reds(n);
		vector<long long> blues(n);

		for (int i = 0; i < n; i++) {
			cin >> reds[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> blues[i];
		}

		dp[0].first = reds[0];
		dp[0].second = reds[1];


	}
}
