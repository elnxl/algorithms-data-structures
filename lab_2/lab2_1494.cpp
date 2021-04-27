#include <iostream>
#include <vector>
using namespace std;

vector<int> sh;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        sh.push_back(i);
        while (!sh.empty() && sh.back() == vec[j])
        {
            sh.pop_back();
            j++;
        }
    }
    if (sh.empty())
        printf("Not a proof\n");
    else
        printf("Cheater\n");
}