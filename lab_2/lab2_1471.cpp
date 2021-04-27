#define SRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
const int N = 50010, R = 20;
long long n, m, T, k;
long long start[N], pt[N], p[R][N], pft[N];
long long temp1[N], temp2[N];
vector<pair<long long, long long>> data[N];

void dfs(int first, int second)
{
    pft[first] = second;
    start[first] = 1;
    temp1[first] = T++;
    for (int i = 0; i < data[first].size(); i++)
    {
        if (!start[data[first][i].first])
        {
            int y = data[first][i].first;
            pt[y] = pt[first] + data[first][i].second;
            if (y == 0)
                continue;
            else
                dfs(y, first);
        }
    }
    temp2[first] = T++;
}
int ch(int a, int b)
{
    return temp1[a] >= temp1[b] && temp2[a] <= temp2[b];
}
int lca(int x, int y)
{
    if (ch(x, y))
        return y;
    if (ch(y, x))
        return x;
    for (int i = k; i >= 0; i--)
    {
        int x0 = p[i][x];
        if (!ch(y, x0))
            x = x0;
    }
    return pft[x];
}

int main()
{
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        data[a].push_back(make_pair(b, c));
        data[b].push_back(make_pair(a, c));
    }
    int f = 1;
    dfs(0, 0);
    while (f <= n)
    {
        f *= 2;
        k++;
    }
    pt[0] = 0;
    for (int i = 0; i < n; i++)
        p[0][i] = pft[i];
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
            p[i][j] = p[i - 1][p[i - 1][j]];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int z = lca(a, b);
        cout << pt[a] + pt[b] - 2 * pt[z] << endl;
    }
    return 0;
}
