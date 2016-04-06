// Problem#: 16981
// Submission#: 4320409
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

typedef struct node {
  char c;
  int weight;
  int level;
  node * lchild;
  node * rchild;
  node(char c = 0, int weight = 0, int level = 0,
       node * lchild = NULL, node * rchild = NULL) {
    this->c = c;
    this->weight = weight;
    this->level = level;
    this->lchild = lchild;
    this->rchild = rchild;
  }
  friend bool operator < (const node  & a, const node & b) {
    return a.weight > b.weight;
  }
} node;

struct cmp{
  bool operator ()(const node * a, const node * b) {
    return a->weight > b->weight;
  }
};

void count_level(node * root) {
  if(root != NULL) {
    root->level++;
    count_level(root->lchild);
    count_level(root->rchild);
  }
}

int huffman(node ** C, int n) {
  priority_queue<node *, vector<node *>, cmp>q;
  int i;
  node * a, * b;
  node * temp = NULL;

  for(i = 0; i < n; i++) {
    q.push(C[i]);
  }

  for(i = 0; i < n-1; i++) {
    a = q.top();
    q.pop();
    b = q.top();
    q.pop();
    temp = new node(0, a->weight+b->weight,-1, a, b);
    count_level(temp);
    q.push(temp);
  }
  node * root = q.top();
  q.pop();

  int res = 0;

  for(i = 0; i < n; i++) {
    res += C[i]->weight * C[i]->level;
  }

  return res;
}

int main() {
  node ** C;
  node * temp;
  int n;
  int i;
  char c;
  int weight;

  cin >> n;

  C = new node*[n];

  for(i = 0; i < n; i++) {
    cin >> c >> weight;
    temp = new node(c, weight);
    C[i] = temp;
  }

  cout  << huffman(C, n) << endl;

  delete C;
  return 0;
}                                 