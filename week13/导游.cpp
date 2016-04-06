// Problem#: 17134
// Submission#: 4369939
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
 
const int MAX = 100;
 
int max(int a, int b) {
  return a > b ? a : b;
}
 
int min(int a, int b) {
  return a < b ? a : b;
}
 
int floyd_warshall(int G[MAX][MAX], int n, int start, int end) {
  int D[MAX][MAX];
  int i, j, k;
 
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      D[i][j] = G[i][j];
   
  for(k = 0; k < n; k++)
    for(i = 0; i < n; i++)
      for(j = 0; j <n; j++)
    D[i][j] = max(D[i][j], min(D[i][k], D[k][j]));
 
  return D[start][end];
}
 
int main() {
  int cases;
 
  int N;  // city number
  int R;  // road number
  int C1, C2;  // the number of city
  int P;  // Path
 
  int S;  // start city
  int E;  // destination city
  int T;  // the numer of visitors
 
  int i, j;
 
  int matrix[MAX][MAX];
 
  int res;
 
  scanf("%d", &cases);
 
  while(cases--) {
    scanf("%d %d", &N, &R);
 
    for(i = 0 ; i < N; i++)
      for(j = 0; j < N; j++)
    matrix[i][j] = 0;
 
    for(i = 0; i < R; i++) {
      scanf("%d %d %d", &C1, &C2, &P);
      matrix[C1-1][C2-1] = matrix[C2-1][C1-1] = P;
    }
 
    scanf("%d %d %d", &S, &E, &T);
 
    res  = floyd_warshall(matrix, N, S-1, E-1);
 
    printf("%d\n", T/(res-1) + (T % (res - 1) ? 1 : 0));
  }
 
  return 0;
}                                 