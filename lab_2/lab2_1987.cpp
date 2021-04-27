#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> coor(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        coor[i] = make_pair(a, b);
    }
    int cur = 1;
    int m;
    cin >> m;
    vector<pair<pair<int, int>, int>> res(m);
    for (int i = 1; i <= m; ++i)
    {
        int c;
        cin >> c;
        int ans = -1;
        while (cur <= n && coor[cur].first <= c)
        {
            if (coor[cur].second >= c)
            {
                ans = cur;
                res.push_back(make_pair(make_pair(coor[cur].first, coor[cur].second), cur));
            }
            cur++;
        }

        if (ans == -1)
        {
            while (!res.empty() && res.back().first.second < c)
                res.pop_back();
            if (!res.empty())
                ans = res.back().second;
        }
        cout << ans << endl;
    }
    return 0;
}