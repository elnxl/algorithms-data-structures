#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
map<int, vector<int>> sta;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "PUSH")
        {
            int x, y;
            cin >> x >> y;
            sta[x].push_back(y);
        }
        else
        {
            int a;
            cin >> a;
            cout << sta[a].back() << '\n';
            if (sta[a].size() == 1)
                sta.erase(a);
            else
                sta[a].pop_back();
        }
    }
}