#include <iostream>
using namespace std;
int main()
{
    long w1;
    long w2;
    long w3;
    cin >> w1;
    cin >> w2;
    cin >> w3;
    int dn = 1;
    int eww = 0;
    int su = (w2 - w1);
    su++;
    int vp;
    for (long e = 1; e < su; ++e)
    {
        cin >> vp;
        if (w3 != vp)
            if (!eww) {
                long cr = vp - w3;
                eww = abs(cr) / (cr);
            }
        else {
            if (vp * eww < w3 * eww) {
                eww = 0;
                dn = dn + 1;;
            }
        }
        w3 = vp;
    }
    //ответ
    cout << dn;
}