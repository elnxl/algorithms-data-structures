#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct dat
{
    int left, right;
    char ch;
};
const int MAXSIZE = 5001;
const int END = 1e9;
dat arr[MAXSIZE];
vector<int> vec;
unordered_map<int, bool> ran;
vector<dat> res;
int main()
{
    int n;
    cin >> n;
    arr[0] = {0, END, 'w'};
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].left >> arr[i].right >> arr[i].ch;
    for (int i = 0; i <= n; ++i)
    {
        if (!ran[arr[i].left])
        {
            vec.push_back(arr[i].left);
            ran[arr[i].left] = 1;
        }
        if (!ran[arr[i].right])
        {
            vec.push_back(arr[i].right);
            ran[arr[i].right] = 1;
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int l = vec[i], r = vec[i + 1];
        for (int j = n; j >= 0; --j)
        {
            if (arr[j].left <= l && arr[j].right >= r)
            {
                res.push_back({l, r, arr[j].ch});
                break;
            }
        }
    }
    int ansl = -1, ansr = -1, ans = 0, curlen = 0;
    char curcol = 0;
    int start = res[0].left;
    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i].ch == curcol)
            curlen += (res[i].right - res[i].left);
        else
        {
            if (curlen > ans && curcol == 'w')
            {
                ans = curlen, ansl = start;
                ansr = res[i].left;
            }
            curcol = res[i].ch;
            start = res[i].left;
            curlen = res[i].right - res[i].left;
        }
    }
    if (curlen > ans && curcol == 'w')
    {
        ans = curlen;
        ansl = start;
        ansr = END;
    }
    cout << ansl << " " << ansr;
    return 0;
}