#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int bgap = s.size();
		for (char i = 'a'; i <= 'z'; i++) {
			int lgap = 0;
			int cgap = 0;

			for (int j = 0; j < s.size(); j++) {
				if (s[j] == i) {
					cgap = 0;
				}
				else {
					cgap++;
				}
				lgap = max(lgap, cgap);
			}

			bgap = min(bgap, lgap);
		}
		bgap++;

		cout << ceill(log2l((long double)bgap)) << endl;
	}
}
