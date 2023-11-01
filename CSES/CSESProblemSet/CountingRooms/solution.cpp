#include <bits/stdc++.h>

using namespace std;

vector<string> rooms;
int n, m;

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && rooms[x][y] == '.';
}

void flood(int x, int y) {
	if (valid(x, y)) {
		rooms[x][y] = '#';

		flood(x + 1, y);
		flood(x - 1, y);
		flood(x, y + 1);
		flood(x, y - 1);
	}
}

int main() {
	cin >> n >> m;

	rooms.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> rooms[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (rooms[i][j] == '.') {
				ans++;
				flood(i, j);
			}
		}
	}

	cout << ans << endl;
}
