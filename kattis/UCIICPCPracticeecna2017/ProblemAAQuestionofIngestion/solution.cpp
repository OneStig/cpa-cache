#include <bits/stdc++.h>

using namespace std;

pair<int, int> dp[105][105];
vector<int> courses;

int main() {
	int n, m;
	cin >> n >> m;

	courses.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> courses[i];
	}

	memset(dp, 0, sizeof(dp));

	for (int c = n - 1; c >= 0; c--) {
		int mx_consume = m;

		dp[c][0].first = min(mx_consume, courses[c]);
		dp[c][0].second = dp[c][0].first;

		for (int r = 1; r <= c; r++) {
			mx_consume = mx_consume * 2 / 3;	
			
		}
	}	
}
