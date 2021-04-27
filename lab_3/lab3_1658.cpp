#include <iostream>

using namespace std;

const int inf = 1000000000;
const int nn = 1000;
const int mm = 8200;

int dp[1000][8200];
int last[1000][8200];
int main()
{
    dp[0][0] = 0;
    int st[10];
    for (int i = 0; i < nn; ++i)
        for (int j = 0; j < mm; ++j)
        {
            dp[i][j] = inf;
            last[i][j] = -1;
        }
    for (int i = 1; i <= 9; ++i)
        st[i] = i * i;
    dp[0][0] = 0;
    for (int i = 1; i < nn; ++i)
        for (int j = 1; j < mm; ++j)
            for (int k = 1; k <= 9; ++k)
                if (i - k >= 0 && j - st[k] >= 0)
                {
                    if (dp[i - k][j - st[k]] + 1 < dp[i][j])
                    {
                        dp[i][j] = dp[i - k][j - st[k]] + 1;
                        last[i][j] = k;

                    }
                }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a >= nn || b >= mm || dp[a][b] == inf || dp[a][b] > 100)
        {
            cout << "No solution" << endl;
            continue;
        }
        while (last[a][b] != -1)
        {
            int k = last[a][b];
            cout << k;
            a = a - k;
            b = b - st[k];
        }
        cout << endl;
    }

    return 0;
}