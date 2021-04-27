#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define LRB '('
#define RRB ')'
#define LSB '['
#define RSB ']'

int main() {
    char * stack = new char[1000000];
    int pointer = -1;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    string sequence;
    for (int i = 0; i < n; i++) {
        fin >> sequence;
        bool isWrong = false;
        pointer = -1;
        for (int j = 0; j < sequence.length() && !isWrong; ++j) {
            if (sequence[j] == LSB || sequence[j] == LRB){
                pointer++;
                stack[pointer] = sequence[j];
            } else {
                if (pointer == -1){
                    isWrong = true;
                }
                else {
                    if (sequence[j] == RRB){
                        stack[pointer] == LRB ? (pointer--) : isWrong = true;
                    } else{
                        stack[pointer] == LSB ? (pointer--) : isWrong = true;
                    }
                }

            }
        }
        isWrong = isWrong || pointer > -1;
        fout << (isWrong ? "NO\n" : "YES\n");
    }
    fin.close();
    fout.close();
    
    return 0;
}