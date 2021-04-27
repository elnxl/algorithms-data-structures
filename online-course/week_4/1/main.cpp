#include <iostream>
#include <fstream>
#include <stack>

using namespace std;


int main() {
    char operation;

    ifstream fin ("input.txt"); 
    int n;
    fin >> n;
    stack <int> stek;

    ofstream fout ("output.txt"); 

    for (int i = 0; i < n; i++) {
        fin >> operation;
        if (operation == '-'){
            fout << stek.top() << '\n';
            stek.pop();}
        else {
            int num;
            fin >> num;
            stek.push(num);
        }
    }
    fin.close();
    fout.close();
    return 0;
}