#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct Node{
    Node* left;
    Node* right;
    int value;
} Node;

int findDepth(Node* node){
    int depth = 1;
    int depthLeft = 0;
    if (node->left != nullptr) depthLeft = findDepth(node->left);
    int depthRight = 0;
    if (node->right != nullptr) depthRight = findDepth(node->right);
    int maxVal = max(depthLeft,depthRight);
    return depth + maxVal;
}

int main() {
    ifstream fin("input.txt");
    int n;
    fin >> n;
    ofstream fout ("output.txt");
    if(n!=0)
    {
      Node *nodes = new Node[n];
      for (int i = 0; i < n; ++i) {
          nodes[i].right = nullptr;
          nodes[i].left = nullptr;
      }
      for (int i = 0; i < n; ++i) {
          int k,l,r;
          fin >> k >> l >> r;
          nodes[i].value = k;
          if (l != 0) nodes[i].left = &(nodes[l - 1]);
          if (r != 0) nodes[i].right = &(nodes[r - 1]);
      }
      fout << findDepth(&(nodes[0]));
    }
    else fout << 0;
    fin.close();
    fout.close();
    return 0;
}