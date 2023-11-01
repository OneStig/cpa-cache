#include <bits/stdc++.h>

using namespace std;

bool grid[102][102];
int offset[] = {-1, 0, 1};

void unfill(int y, int x) {
	grid[y][x] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[y + offset[i]][x + offset[j]]) {
				unfill(y + offset[i], x + offset[j]);
			}
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;

	memset(grid, 0, sizeof(grid));

	for (int i = 1; i <= m; i++) {
		string cur;
		cin >> cur;

		for (int j = 1; j <= n; j++){
			grid[i][j] = (cur[j - 1] == '#');
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (grid[i][j]) {
				unfill(i, j);
				ans++;
			}
		}
	}

	cout << ans << endl;
}
