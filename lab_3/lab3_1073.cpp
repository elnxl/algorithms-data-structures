#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    const int o = 1e5;
    long long t[o];
    vector <long long> V;
    int K;
    cin >> K;
    int p = 1015;

    for (int y = 1; y < p; y++)
        V.push_back(y * y);

    int p1 = 60001;
    for (int i = 0; i < p1; ++i) {
        if (i == 0) {
            t[0] = 0;
            continue;
        }
        if (i == 1) {
            t[1] = 1;
            continue;
        }
        t[i] = 1e9;

    }


    for (int y1 = 2; y1 < p1; y1++) {
        for (int y2 = 0; y2 < V.size(); ++y2) {
            if (y1 - V[y2] >= 0) t[y1] = min(t[y1 - V[y2]] + 1, t[y1]);
        }
    }

    cout << t[K];
    return 0;
}