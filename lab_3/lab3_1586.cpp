#include <iostream>

using namespace std;

using LL = long long;
const LL MOD = 1e9 + 9;
const LL ARR1 = 10501;
const LL ARR2 = 11;

LL AR[ARR1][ARR2][ARR2], N;

bool f_1(LL a) {

    LL u = 100;
    if (a < u)
        return false;

    for (int i_1 = 2; i_1 <= sqrt(a); ++i_1)
        if (a % i_1 == 0)
            return false;

    return true;
}


bool f_2(LL c0, LL c1, LL c2) {

    if (f_1(c0 * 100 + c1 * 10 + c2))
        return true;

    return false;
}

void f() {
    for (LL a = 3; a < N; ++a) {
        for (LL b = 0; b <= 9; ++b) {
            for (LL c = 0; c <= 9; ++c) {
                for (LL d = 0; d <= 9; ++d) {
                    if (f_2(b, c, d)) {
                        AR[a + 1][c][d] += AR[a][b][c];
                        AR[a + 1][c][d] %= MOD;
                    }
                }
            }
        }
    }
}

int main() {

    cin >> N;

    for (int it = 1e2; it < 1e3; ++it)
        if (f_1(it))
            AR[3][(it / 10) % 10][it % 10]++;

    f();

    LL hps = 0;

    for (LL a = 0; a < 10; ++a) {
        for (LL b = 0; b < 10; ++b) {
            hps += AR[N][a][b];
            hps %= MOD;
        }
    }

    cout << hps;
    return 0;
}
