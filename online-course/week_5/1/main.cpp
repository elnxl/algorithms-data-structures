#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int ceil(int x, int y) {
	return x / y + (x % y != 0);
}

int main()
{
	int n;
  fin >> n;
  int* arr = new int[n];
  bool flag = true;
  for (int i = 0; i < n; i++) {
    fin >> arr[i];
    if (i >= 1 && arr[i] < arr[ceil(i, 2) - 1]) {
      //cout << "apparently, " << arr[i] << " < " << arr[i / 2] << endl;
      flag = false;
      break;
    }
  }
  flag ? fout << "YES" : fout << "NO";
  delete[] arr;
  fout.close();
  fin.close();
	return 0;
}