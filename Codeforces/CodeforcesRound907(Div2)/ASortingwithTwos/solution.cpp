#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;
		vector<int> nums(n + 1);
		vector<bool> special(n + 1);

		int k = 1;
		for (int i = 0; i < n; i++) {
			cin >> nums[i + 1];
			if (k <= 20) {
				special[k] = 1;
				k *= 2;
			}
		}

		int fail = 0;
		for (int i = 1; i <= n -1; i++) {
			if (nums[i] > nums[i + 1] && !special[i]) {
				fail = 1;
				break;
			}
		}

		cout << (fail ? "NO" : "YES") << endl;
	}
}
