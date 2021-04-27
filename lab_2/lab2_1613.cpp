#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct test
{
    int l;
    int r;
    unsigned int x;
};

int main()
{
    int n;
    scanf("%d", &n);
    map<unsigned int, vector<unsigned int>> ch;
    for (int i = 1; i <= n; ++i)
    {
        unsigned int tmp;
        scanf("%d ", &tmp);
        ch[tmp].push_back(i);
    }
    int q;
    scanf("%d", &q);
    vector<test> data(q);
    for (int i = 0; i < data.size(); ++i)
    {
        scanf("%d %d %d", &data[i].l, &data[i].r, &data[i].x);
        auto val = ch.find(data[i].x);
        if (val == ch.end())
            printf("%d", 0);
        else
        {
            auto it = lower_bound(val->second.begin(), val->second.end(), data[i].l);
            if (it == val->second.end() || (*it) > data[i].r)
                printf("%d", 0);
            else
                printf("%d", 1);
        }
    }
    return 0;
}