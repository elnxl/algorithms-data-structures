#include <iostream>

using namespace std;

int n;
int k;
int out;
int Q[3000][3000];

int main() {
    cin >> n;
    cin >> k;

    int iter;
    int iter_j;
    int iter_i;

    for (iter = 1; iter < k; iter = iter + 1)
        Q[1][iter] = 1;

    for (iter = 1; iter <= n; iter = iter + 1) 
    {
        for (iter_j = 0; iter_j < k; iter_j = iter_j + 1) 
        {
            if (iter_j == 0) 
            {
                for (iter_i = 1; iter_i < k; iter_i = iter_i + 1) 
                     Q[iter + 1][iter_i] += Q[iter][iter_j];
            }
            else {
                for (iter_i = 0; iter_i < k; iter_i = iter_i + 1) 
                    Q[iter + 1][iter_i] += Q[iter][iter_j];
            }
        }
    }
    for (iter = 0; iter < k; iter = iter + 1) 
        out += Q[n][iter];

    cout << out;

    return 0;
}