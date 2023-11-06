#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<string> grid(n);

	vector<vector<long long> > paths(n);

	for (int i = 0; i < n; i++) {
		paths[i].resize(n);
		cin >> grid[i];
	}

	paths[0][0] = grid[0][0] == '.';
	for (int i = 1; i < n; i++) {
		paths[i][0] = paths[i - 1][0] * (grid[i][0] == '.');
		paths[0][i] = paths[0][i - 1] * (grid[0][i] == '.');
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == '.') {
				paths[i][j] += paths[i - 1][j];
				paths[i][j] %= MOD; 
				paths[i][j] += paths[i][j - 1];
				paths[i][j] %= MOD;
			}
		}
	}

	cout << paths[n - 1][n - 1] << endl;
}
