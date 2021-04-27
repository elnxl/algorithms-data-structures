#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    char c[200000];
    int check=-1;
    for (char & i : c) 
          i = ' ';
    for (char i : str) {
          if (check > -1) {
               if (c[check] == i) {
                    c[check] = ' ';
                    check--;
               } else {
                    check++;
                    c[check] = i;
                    continue;
               }
          }
          else {
               check++;
               c[check] = i;
          }
     }
     for (char i : c) {
          if (i != ' ') {
               cout << i;
          }
     }
    return 0;
    }