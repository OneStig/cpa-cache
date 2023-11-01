#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, s1, s2;
		cin >> n >> s1 >> s2;

		vector<pair<int, int> > r(n);
		
		for (int i = 0; i < n; i++) {
			int freq;
			cin >> freq;
			r[i] = make_pair(freq, i);
		}

		sort(r.rbegin(), r.rend());


		vector<int> a;
		vector<int> b;

		for (int i = 0; i < n; i++) {
			if ((a.size() + 1) * s1 < (b.size() + 1) * s2) {
				a.push_back(r[i].second);
			}
			else {
				b.push_back(r[i].second);
			}
		}

		cout << a.size();
		for (auto x : a) {
			cout << " " << x + 1;
		}
		cout << endl;

		cout << b.size();
		for (auto x : b) {
			cout << " " << x + 1;
		}
		cout << endl;
	}
}
