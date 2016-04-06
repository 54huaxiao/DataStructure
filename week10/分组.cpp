// Problem#: 16701
// Submission#: 4224803
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <vector>
using std::vector;

int m, n, t;
double sum;
std::vector< vector<int> > table(11);

int hash(int key) {
    return key % t;
}

void insert_hash(int key, int value) {
    table[key].push_back(value);
    sum += table[key].size();
}

void clear() {
    for (int i = 0; i < t; i++) {
        table[i].clear();
    }
}

void print() {
    for (int i = 0; i < t; i++) {
        for (int j = table[i].size() - 1; j >= 0; --j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("%.3lf\n", sum / n);
}

int main() {
    while (scanf("%d%d", &n, &t) != EOF) {
        int num;
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            insert_hash(hash(num), num);
        }
        print();
        clear();
    }
    return 0;
}                                 