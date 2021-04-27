#include <iostream>
#include <string>
#include <deque>
#include <fstream>

using namespace std;


int main() {
    char operation;
    long* queue = new long[1000000];
    int pointerEnd = -1;
    int pointerStart = 0;
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n;
    fin >> n;

    deque<long> deque;

    for (int i = 0; i < n; i++) {
        fin >> operation;
        if (operation == '-') {
            if (deque.front() == queue[pointerStart]){
                deque.pop_front();
            }
            pointerStart++;
        } else if (operation == '?'){
            fout << to_string(deque.front()) << '\n';
        } else {
            pointerEnd++;
            fin >> queue[pointerEnd];
            while (!deque.empty() && deque.back() > queue[pointerEnd]) {
                deque.pop_back();
            }
            deque.push_back(queue[pointerEnd]);
        }
    }
    fin.close();
    fout.close();
    return 0;
}