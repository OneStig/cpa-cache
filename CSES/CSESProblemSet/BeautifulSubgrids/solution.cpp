#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<bool> > grid(n);

	for (int i = 0; i < n; i++) {
		grid[i].resize(n);

		string bstring;
		cin >> bstring;

		for (int j = 0; j < n; j++) {
			grid[i][j] = bstring[j] - '0';
		}
	}


}
