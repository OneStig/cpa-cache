#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int prev;

	cin >> prev;
	int cur;
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		cin >> cur;
		if (cur < prev) {
			ans += prev - cur;
		} else {
			prev = cur;
		}
	}

	cout << ans << endl;
}
