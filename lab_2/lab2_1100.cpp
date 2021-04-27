#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define size 150001
using namespace std;

struct abc
{
    int a;
    int b;
} abcs[size];

bool foo(abc lhs, abc rhs)
{
    return lhs.b > rhs.b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> abcs[i].a >> abcs[i].b;
    }
    cout << "\n";
    stable_sort(abcs, abcs + n, foo);
    /*for (int i = 0; i < n - 1; i++)
    {
        int flag=0;
        for (int j = 0; j < n - i - 1; j++)
        {
            flag=1;
            if (p[j].b < p[j + 1].b)
            {
                swap(p[j], p[j + 1]);
            }
            if(flag==0)
            break;
        }
    }*/
    for (int i = 0; i < n; i++)
    {
        cout << abcs[i].a << " " << abcs[i].b << '\n';
    }
    return 0;
}