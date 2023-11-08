#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<char> m[3];

		for (int i = 0; i < n; i++) {
			m[i % 2].push_back(s[i]);
			m[2].push_back(s[i]);
		}

		for (int i = 0; i < 3; i++) {
			sort(m[i].begin(), m[i].end());
		}

		if (k % 2) {
			for (int i = 0; i < n; i++) {
				cout << m[i % 2][i / 2];
			}
		}	
		else {
			for (int i = 0; i < n; i++) {
				cout << m[2][i];
			}
		}

		cout << endl;
	}
}
