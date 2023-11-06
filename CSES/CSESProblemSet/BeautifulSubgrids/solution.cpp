#include <bits/stdc++.h>

using namespace std;

const int N = 64;

int main() {
	int n;
	cin >> n;

	vector<vector<bool> > grid(n);
	vector<vector<long long> > g(n);

	for (int i = 0; i < n; i++) {
		grid[i].resize(n);
		g.resize((n + N - 1) / N);

		string bstring;
		cin >> bstring;

		long long cur = 0;
		int shifts = 0;
		for (int j = 0; j < n; j++) {
			grid[i][j] = bstring[j] - '0';

			if (shifts == N) {
				g[i][]
			}
		}
	}
}
