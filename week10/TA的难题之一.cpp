// Problem#: 16702
// Submission#: 4225132
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>

#define MAX 302
#define NUM 12
int numOfStudents, numOfProblem;
int table[MAX][NUM] = {0};

int main() {
    int id, pro_num;
    scanf("%d%d", &numOfStudents, &numOfProblem);
    while (scanf("%d%d", &id, &pro_num) != EOF) {
        table[id][pro_num]++;
    }
    for (int i = 1; i < numOfStudents + 1; ++i) {
        for (int j = 1; j < numOfProblem; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("%d\n", table[i][numOfProblem]);
    }
    return 0;
}                                 