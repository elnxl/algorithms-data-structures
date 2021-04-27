#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    if (m<2)
        return 0;
    int n[25001];
    int check =sizeof(n)/sizeof(int);
    for (int i=0;i<check;++i)
    {
        cin >> n[i];
        if (i>=m)
            cout << *max_element(n+i-m,n+i) << '\n';
        if (n[i] == -1)
            break;
    }
    return 0;
}
