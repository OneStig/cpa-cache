#include <bits/stdc++.h>

using namespace std;

long long cnt[6][46];

int main() {
	int n;
	cin >> n;

	memset(cnt, 0, sizeof(cnt));

	long long ans = 0;
	vector<string> inp;
	vector<int> sizes;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int len = s.size();
		int ssum = 0;

		for (int j = 0; j < s.size(); j++) {
			ssum += s[j] - '0';
		}

		cnt[len][ssum]++;

		inp.push_back(s);
		sizes.push_back(ssum);
	}

	for (int i = 0; i < n; i++) {
		string cur = inp[i];
	
		int searchsum = sizes[i];
		ans += cnt[cur.size()][searchsum];

		int removed = 0;

		for (int j = 0; j < (cur.size() - 1) / 2; j++) {
			removed += cur[j] - '0';
			int numremoved = j + 1;
			int needsum = searchsum - 2 * removed;

			ans += cnt[cur.size() - 2 * numremoved][needsum];
		}

		removed = 0;
		for (int j = cur.size() - 1; j > cur.size() / 2; j--) {
			removed += cur[j] - '0';
			int numremoved = cur.size() - j;
			int needsum = searchsum - 2 * removed;

			ans += cnt[cur.size() - 2 * numremoved][needsum];
		}
	}

	cout << ans << endl;
}
