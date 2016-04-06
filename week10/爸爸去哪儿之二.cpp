// Problem#: 16700
// Submission#: 4223925
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <iomanip>

#define MAX 10001

int m, n;
double sum;
char *table[MAX];

void init() {
    sum = 0;
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }
}

int nameValue(char * name) {
    int value = 0;
    while (*name != '\0') {
        value += (*name++ - 'a' + 1);
    }
    return value;
}

int hash(int key) {
    return key % m;
}

void insert_hash(int key, char *name) {
    int i, index = key;
    sum++;
    for (i = 0; key < MAX && table[key % m] != NULL; i++, key = index + i*i) sum++;
    table[key % m] = name;
}

void print() {
    for (int i = 0; i < m; i++) {
        printf("%d:", i);
        if (table[i] != NULL) {
            printf("%s\n", table[i]);
        } else {
            printf("NULL\n");
        }
    }
    printf("%.3lf\n", sum / n);
}

void free_new() {
    for (int i = 0; i < m; i++) {
        if (table[i] != NULL) {
            delete table[i];
            table[i] = NULL;
        }
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        int index;
        for (int i = 0; i < n; i++) {
            char * name = new char[11];
            scanf("%s", name);
            index = hash(nameValue(name));
            insert_hash(index, name);
        }
        print();
        free_new();
    }
    return 0;
}                                 