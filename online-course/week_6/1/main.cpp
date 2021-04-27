#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int binSearch(const int *arr, int n, int value){
    int l = -1;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] < value)
            l = m;
        else
            r = m;
      
    }
    if (r < n && arr[r] == value)
        return r;
    else
        return -1;
}


int searchMax(int *arr, int n, int value, int leftIndex){
    int l = leftIndex;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] == value)
            l = m;
         else 
            r = m;
        
    }
    return l;
}

int main() {
    ifstream fin("input.txt");
    int n;
    fin >> n;
    int* arr = new int[n+1];
    for (int i = 0; i < n; ++i)
        fin >> arr[i];
    ofstream fout("output.txt");
    int requestCount;
    fin >> requestCount;
    for (int i = 0; i < requestCount; ++i) {
        int value;
        fin >> value;
        int indexMin = binSearch(arr, n, value);
        if (indexMin == -1)
            fout << indexMin << ' ' << indexMin << '\n';
        else {
            int indexMax = searchMax(arr, n, value, indexMin);
            fout << indexMin + 1 << ' ' << indexMax + 1 << '\n';
        }
    }
    fin.close();
    fout.close();
    return 0;
}