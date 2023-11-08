#include <bits/stdc++.h>

using namespace std;

const int MX = 20; 
vector<array<int, 2> > btrie;

int search(int x) {
	int v = 0;

	for (int i = MX; i >= 0; i--) {
		int cur = (x >> i) & 1;

		if (btrie[v][cur ^ 1]) {
			cur ^= 1;
		}

		v = btrie[v][cur];
		cur = cur << i;
		x ^= cur;
	}

	return x;
}

void add(int x) {
	int v = 0;

	for (int i = MX; i >= 0; i--) {
		int cur = (x >> i) & 1;

		if (!btrie[v][cur]) {
			btrie[v][cur] = btrie.size();
			btrie.push_back({0, 0});
		}

		v = btrie[v][cur];
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	btrie.push_back({0, 0});

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
		add(a[i]);
	}

	int start = n - 1;
	for (int tst = 0; tst < n; tst++) {
		if (search(tst) == n - 1) {
			start = tst;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << " ";
		}

		cout << (start ^ a[i]);
	}

	cout << endl;
}
