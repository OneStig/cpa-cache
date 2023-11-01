#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

vector<string> grid;
vector<string> dirs;

pair<int, int> ofs[] = {
	make_pair(1, 0),
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(0, -1)
};

char desc[] = {
	'D',
	'U',
	'R',
	'L'
};

int n, m;

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

int main() {
	cin >> n >> m;

	grid.resize(n);
	dirs.resize(n);

	int sx, sy;

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		dirs[i] = grid[i];

		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'A') {
				sx = i;
				sy = j;
			}
		}
	}

	int depth = 0;

	vector<pair<int, int> > bfs;
	bfs.push_back(make_pair(sx, sy));

	int found = 0;
	int fx, fy;

	for (int d = 0; true; d++) {
		vector<pair<int, int> > nbfs;
		for (int i = 0; i < bfs.size(); i++) {
			int cx = bfs[i].first;
			int cy = bfs[i].second;
			
			if (grid[cx][cy] == 'B') {
				found = d;
				fx = cx;
				fy = cy;
				break;
			}

			grid[cx][cy] = '#';

			for (int o = 0; o < 4; o++) {
				int nx = cx + ofs[o].first;
				int ny = cy + ofs[o].second;

				if (valid(nx, ny)) {
					nbfs.push_back(make_pair(nx, ny));
					dirs[nx][ny] = desc[o];
				}
			}
		}

		bfs = nbfs;
		if (found) {
			break;
		}
	}

	if (!found) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl << found << endl;
		//backtrak

		vector<char> backtrack;

		while (fx != sx || fy != sy) {
			backtrack.push_back(dirs[fx][fy]);

			if (dirs[fx][fy] == 'U') {
				fx++;
			}
			else if (dirs[fx][fy] == 'D') {
				fx--;
			}
			else if (dirs[fx][fy] == 'R') {
				fy--;
			}
			else {
				fy++;
			}
		}

		reverse(backtrack.begin(), backtrack.end());

		for (int i = 0; i < backtrack.size(); i++) {
			cout << backtrack[i];
		}
		cout << endl;
	}
}

