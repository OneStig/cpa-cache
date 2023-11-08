#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		char last = 'a';
		int cons = 0;
		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == last) {
				cons++;
			} else {
				cons = 1;
				last = s[i];
			}

			ans = max(ans, cons);
		}

		cout << ans + 1 << endl;
	}
}
