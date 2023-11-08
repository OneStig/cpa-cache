#include <bits/stdc++.h>

using namespace std;

const int N = 64;

int main() {
	int n;
	cin >> n;

	vector<bitset<3000> > grid(n);

	for (int i = 0; i < n; i++) {
		string bstring;
		cin >> bstring;

		for (int j = 0; j < n; j++) {
			grid[i][j] = bstring[j] - '0';
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int count = (grid[i] & grid[j]).count();
			ans += (count * (count - 1)) / 2;
		}
	}

	cout << ans << endl;
}
