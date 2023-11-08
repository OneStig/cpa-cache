#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 1;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	for (int i = 1; i < n; i++) {
		if (nums[i] != nums[i - 1]) {
			ans++;
		}
	}

	cout << ans << endl;
}
