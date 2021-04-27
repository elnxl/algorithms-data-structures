#include <iostream>
#include <fstream>
#include <queue>

using namespace std;


int main() {
    char operation;

    ifstream fin ("input.txt"); 
    int n;
    fin >> n;
    queue <int> que;

    ofstream fout ("output.txt"); 

    for (int i = 0; i < n; i++) {
        fin >> operation;
        if (operation == '-'){
            fout << que.front() << '\n';
            que.pop();}
        else {
            int num;
            fin >> num;
            que.push(num);
        }
    }
    fin.close();
    fout.close();
    return 0;
}