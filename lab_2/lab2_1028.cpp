#define SRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int N = 32100, M = 15100;
int n, tmp[N], res[M];
pair<int, int> v[M];

long long sum(int a)
{
    a++;
    long long res = 0;
    while (a > 0)
    {
        res += tmp[a];
        a &= a - 1;
    }
    return res;
}
void upd(int x, long long y)
{
    x++;
    while (x <= N)
    {
        tmp[x] += y;
        x |= x - 1;
        x++;
    }
}

int main()
{
    cin >> n;
    for (int cnt = 0; cnt < (n); cnt++)
        cin >> v[cnt].first >> v[cnt].second;
    sort(v, v + n);
    for (int cnt = 0; cnt < (n); cnt++)
    {
        upd(v[cnt].second + 1, 1);
        res[sum(v[cnt].second + 1)]++;
    }
    for (int cnt = 0; cnt < (n); cnt++)
        cout << res[cnt + 1] << endl;
    return 0;
}