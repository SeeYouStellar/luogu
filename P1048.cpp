#include <bits/stdc++.h>
using namespace std;
int t, m, dp[1002];
int main()
{
    cin >> t >> m;
    vector<pair<int, int>> v(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> v[i].first >> v[i].second;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= t; j++)
        {
            if (v[i].first < j)
                dp[j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
            else
                dp[j] = dp[i - 1][j]
        }

    cout << dp[m][t] << endl;
    system("pause");
}