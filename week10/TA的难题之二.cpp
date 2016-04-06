// Problem#: 16703
// Submission#: 4225138
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>

#define MAX 302
#define NUM 12
int numOfStudents, numOfProblem;
int table[MAX][NUM][2] = {0};

int main() {
    int id, pro_num, pass;
    scanf("%d%d", &numOfStudents, &numOfProblem);
    while (scanf("%d%d%d", &id, &pro_num, &pass) != EOF) {
        table[id][pro_num][pass]++;
    }
    for (int i = 1; i < numOfStudents + 1; ++i) {
        for (int j = 1; j < numOfProblem; ++j) {
            printf("%d %d ", table[i][j][1], table[i][j][0]);
        }
        printf("%d %d\n", table[i][numOfProblem][1], table[i][numOfProblem][0]);
    }
    return 0;
}                                 