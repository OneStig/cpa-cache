#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> nums;

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		string bs;
		cin >> bs;

		int cur = 0;
		for (int j = 0; j < bs.size(); j++) {
			cur = cur << 1;
			cur += bs[j] - '0';
		}

		for (int j = 0; j < nums.size(); j++) {
			ans = min(ans, __builtin_popcount(cur ^ nums[j]));
		}

		nums.push_back(cur);
	}

	cout << ans << endl;
} 
