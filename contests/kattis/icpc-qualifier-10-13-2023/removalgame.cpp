#include <bits/stdc++.h>

using namespace std;

int dp[201][201];
int gcf[1001][1001];

// 4 2 3 4 5
// 5 14 2 4 6 8
// 0

// bottom up dp approach?

int gcd(int a, int b)
{
    if (gcf[a][b] != 0) {
        return gcf[a][b];
    }

    if (b)
    {
        int k = gcd(b, a % b);

        gcf[a][b] = k;
        gcf[b][a] = k;
        return k;
    }
    else
    {
        gcf[a][b] = a;
        gcf[b][a] = a;
        return a;
    }
}

int nums[200];

int main()
{
    // precompute gcd

    memset(gcf, 0, sizeof(gcf));

    for (int i = 1000; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            gcd(i, j);
        }
    }

    int n;
    cin >> n;

    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];

            //read it in twice for wrap around
            nums[i + n] = nums[i];
        }

        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = i + 1; j < 2 * n; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }

        for (int len = 0; len < n; len++)
        {
            for (int i = 0; i + len < 2 * n - 1; i++)
            {
                for (int k = i; k < len + i; k++)
                {
                    int curgcf;

                    if (len + i + 1 == i + n) {
                        curgcf = gcd(nums[i], nums[k + 1]);
                    }
                    else {
                        curgcf = gcd(nums[i], nums[len + i + 1]);
                    }
                    
                    dp[i][i + len] = min(dp[i][i + len], dp[i][k] + dp[k + 1][len + i] + curgcf);
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[i][i + n - 1]);
        }

        cout << ans << endl;
        cin >> n;
    }
}