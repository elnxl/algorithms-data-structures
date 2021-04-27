#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 300001;
ll M, n, q;
vector<ll> res(N);
vector<ll> a(N);

ll sum(int f)
{
    f++;
    ll answer = 0;
    while (f > 0)
    {
        answer += res[f];
        f &= f - 1;
    }
    return answer;
}
void upd(int y, ll d)
{
    y++;
    while (y <= N)
    {
        res[y] += d;
        y |= y - 1;
        y++;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a.shrink_to_fit();
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int cur;
            cin >> cur;
            ll answer = a[cur - 1];
            for (int j = 1; j * j <= cur; j++)
            {
                if (cur == j * j)
                    answer += sum(j);
                else if (cur % j == 0)
                    answer += sum(j) + sum(cur / j);
            }
            cout << answer << '\n';
        }
        else
        {
            int l, r, d;
            cin >> l >> r >> d;
            r++;
            upd(l, d);
            upd(r, -d);
        }
    }
}