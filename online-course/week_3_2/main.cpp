#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ifstream fin ("input.txt");
    int n,m,k;
    fin >> n >> m >> k;
    
    // auto ** matrix = new char*[m];
    // auto ** tmpmatrix = new char*[m];

    // for (int i = 0; i < m; ++i) {
    //     matrix[i] = new char[n];
    //     tmpmatrix[i] = new char[n];
    // }
    vector <vector<char>> matrix(m,vector<char> (n));
    vector <vector<char>> tmpmatrix(m,vector<char> (n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> matrix[i][j];
            tmpmatrix[i][j] = matrix[i][j];
        }
    }
    fin.close();


    //int* c = new int[k];
    vector <int> c (123);
    //int* indexes = new int[n];
    //int* tmpindexes = new int[n];
    vector <int> indexes (n);
    vector <int> tmpindexes (n);
    for (int i = 0; i < n; ++i) {
        indexes[i] = i;
        tmpindexes[i] = i;
    }

    for (int i = 0; i < k; ++i) {

        for (char j = 97; j < 123; ++j) {
            c[j] = 0;
        }
	c.shrink_to_fit();
        for (int j = 0; j < n; ++j) {
            c[matrix[m-i-1][j]]++;
        }

        for (int j = 98; j < 123; ++j) {
            c[j] += c[j-1];
        }

        for (int j = n-1; j >= 0; j--){

            int indexReplace = c[matrix[m-i-1][j]] - 1;

            c[matrix[m-i-1][j]]--;

            for (int i2 = 0; i2 < m; ++i2) {
                tmpmatrix[i2][indexReplace] = matrix[i2][j];
            }

            tmpindexes[indexReplace] = indexes[j];

        }

        for (int i2 = 0; i2 < m; ++i2) {
            for (int j2 = 0; j2 < n; ++j2) {
                matrix[i2][j2] = tmpmatrix[i2][j2];
            }
        }

        for (int i2 = 0; i2 < n; ++i2) {
            indexes[i2] = tmpindexes[i2];
        }

    }

    ofstream fout ("output.txt");
    for (int i = 0; i < n; ++i) {
        fout << indexes[i] + 1 << ' ';
    }
    fout.close();

    return 0;
}
