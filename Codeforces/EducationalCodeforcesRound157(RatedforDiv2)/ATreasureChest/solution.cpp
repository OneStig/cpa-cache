#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int x, y, k;
		cin >> x >> y >> k;

		if (x > y) {
			cout << x << endl;
			continue;
		}

		x += k;

		if (x >= y) {
			cout << y << endl;
		}
		else {
			cout << (2 * y - x) << endl;
		}
	}
}
