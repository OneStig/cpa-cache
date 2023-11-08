#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

// up, right, down, left

int dx[] {
	0,
	1,
	0,
	-1
};

int dy[] {
	-1,
	0,
	1,
	0
};

char dirs[] {
	'U',
	'R',
	'D',
	'L'
};

int n, m;
vector<string> grid;
vector<vector<bool> > visited;
vector<vector<int> > dists;
vector<vector<char> > last;

bool validate(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m && !visited[y][x] && grid[y][x] != '#';
}

int main() {
	cin >> n >> m;

	grid.resize(n);
	visited.resize(n);
	dists.resize(n);
	last.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		visited[i].resize(m);
		dists[i].resize(m);
		last[i].resize(m);
	}

	int sy, sx;
	for (int i = 0; i < n; i++) {
		int b = 0;
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'A') {
				sy = i;
				sx = j;
				b = 1;
				break;
			}
		}

		if (b) {
			break;
		}
	}

	vector<array<int, 2> > visit;
	visit.push_back({sy, sx});

	int ansy = -1, ansx = -1;

	while (visit.size()) {
		vector<array<int, 2> > newvst;

		for (auto it = visit.begin(); it != visit.end(); it++) {
			int cy = (*it)[0];
			int cx = (*it)[1];

			if (grid[cy][cx] == 'B') {
				ansy = cy;
				ansx = cx;

				vector<array<int, 2> > empt;
				visit = empt;
				break;
			}

			for (int j = 0; j < 4; j++) {
				int ny = cy + dy[j];
				int nx = cx + dx[j];

				if (validate(ny, nx)) {
					newvst.push_back({ny, nx});
					last[ny][nx] = dirs[j];
					dists[ny][nx] = dists[cy][cx] + 1;
					visited[ny][nx] = 1;
				}
			}
		}

		visit = newvst;
	}

	if (ansy == -1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl << dists[ansy][ansx] << endl;

		vector<char> anspath;

		while (ansy != sy || ansx != sx) {
			anspath.push_back(last[ansy][ansx]);

			for (int i = 0; i < 4; i++) {
				if (last[ansy][ansx] == dirs[i]) {
					i = (i + 2) % 4;
					ansy += dy[i];
					ansx += dx[i];
					break;
				}
			}
		}

		for (int i = anspath.size() - 1; i >= 0; i--) {
			cout << anspath[i];
		}

		cout << endl;
	}
}
