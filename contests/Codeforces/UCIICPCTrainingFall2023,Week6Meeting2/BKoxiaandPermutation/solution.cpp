#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> ans;

		int a = 1, b = n;

		for (int i = 0; i < n; i++) {
			ans.push_back(b);
			ans.push_back(a);
			a++;
			b--;
		}

		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << " ";
			}

			cout << ans[i];
		}

		cout << endl;
	}
}
