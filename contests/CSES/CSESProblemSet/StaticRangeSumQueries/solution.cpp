#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> nums(n + 1);

	vector<long long> sums(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		sums[i] = nums[i] + sums[i - 1];	
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << sums[b] - sums[a - 1] << endl;
	}
}
