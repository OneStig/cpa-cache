#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
 
	while (t--) {
		int n;
		cin >> n;

		vector<int> nums(2 * n);

		for (int i = 0; i < 2 * n; i++) {
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end());

		int ans = nums[n - 1] - nums[0] + nums[n * 2 - 1] - nums[n];

		cout << ans << endl;

		for (int i = 0; i < n; i++) {
			cout << nums[i] << " " << nums[n + i] << endl;
		}
	}
}
