#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
    char operation;

    ifstream fin ("input.txt"); 
    int n;
    fin >> n;
    deque <int> que;

    ofstream fout ("output.txt"); 

    for (int i = 0; i < n; i++) {
      fin >> operation;
      switch (operation){
        case '-':
          que.pop_front();
          break;
        case '+':
          int num;
          fin >> num;
          que.push_back(num);
          break;
        default:
          fout << *min_element(que.begin(),que.end()) << '\n';
          break;
      }
    }
    fin.close();
    fout.close();
    return 0;
}