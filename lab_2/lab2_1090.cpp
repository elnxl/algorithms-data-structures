#include <bits/stdc++.h>

using namespace std;

int mergeSort(vector<int> &temp, vector<int> &height, int sortleft, int sortright);

int main()
{
    int n, k;
    int res = 0;
    int ans = 1;
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        vector<int> tmp1(n);
        for (int j = 0; j < n; ++j)
            cin >> tmp1[j];
        vector<int> tmp = tmp1;
        int r = mergeSort(tmp1, tmp, 0, tmp1.size() - 1);
        if (r > res)
        {
            res = r;
            ans = i + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}

int mergeSort(vector<int> &temp, vector<int> &height, int sortl, int sortr)
{
    if (sortl == sortr)
        return 0;
    int tmp2 = (sortl + sortr) / 2;
    int cnt = mergeSort(temp, height, sortl, tmp2) + mergeSort(temp, height, tmp2 + 1, sortr);
    int sort1 = sortl;
    int sort2 = tmp2 + 1;
    int pos = sortl;
    while (sort1 <= tmp2 && sort2 <= sortr)
    {
        if (temp[sort1] > temp[sort2])
        {
            height[pos++] = temp[sort2++];
            cnt += (tmp2 - sort1 + 1);
        }
        else
            height[pos++] = temp[sort1++];
    }
    for (int i = sort1; i <= tmp2; ++i)
        height[pos++] = temp[i];
    for (int i = sort2; i <= sortr; ++i)
        height[pos++] = temp[i];
    for (int i = sortl; i <= sortr; ++i)
        temp[i] = height[i];
    return cnt;
}