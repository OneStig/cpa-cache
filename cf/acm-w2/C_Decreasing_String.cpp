#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    // dacb
    // acb
    // ab
    // a

    while (t--)
    {
        string s;
        long long pos;
        cin >> s >> pos;
        int n = s.size();

        int removals = 0;

        for (; n - removals < pos; removals++) {
            pos -= n - removals;
        }
        
        vector<int> notorder, toremove;

        for (int i = 0; i < n; i++) {
            while (!notorder.empty() && s[notorder.back()] > s[i]) {
                toremove.push_back(notorder.back());
                notorder.pop_back();
            }

            notorder.push_back(i);
        }

        vector<int> remove_order;

        int until = 0;

        for (int i = 0; i < toremove.size(); i++) {
            if (until < removals) {
                until++;
                continue;
            }

            remove_order.push_back(toremove[i]);
        }

        for (int i = notorder.size() - 1; i >= 0; i--) {
            if (until < removals) {
                until++;
                continue;
            }
            
            remove_order.push_back(notorder[i]);
        }

        sort(remove_order.begin(), remove_order.end());

        cout << s[remove_order[pos - 1]];
    }
}
