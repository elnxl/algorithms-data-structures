#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<unsigned int> arr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr.shrink_to_fit();
    if (!(is_sorted(arr.begin(), arr.end())))
        sort(arr.begin(), arr.end());
    double sum;
    if (n % 2 == 1)
        sum = arr[(n - 1) / 2];
    else
        sum = (arr[n / 2] + arr[n / 2 - 1]) * 0.5;
    printf("%.1f\n", sum);
    return 0;
}