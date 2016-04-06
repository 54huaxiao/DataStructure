// Problem#: 16583
// Submission#: 4180845
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstdio>
using namespace std;

int s[10000000];

void qsort(int l, int r) {
    int i, j, x;
    if (l < r) {
        i = l;
        j = r;
        x = s[i];
        while (i < j) {
            while (i < j && s[j] < x)
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] > x)
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        qsort(l, i - 1);
        qsort(i + 1, r);
    }
}
int main() {
    int n, k, i;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        qsort(0, n - 1);
        int max = s[0];
        for (int i = 0; i < k-1; i++) {
            cout << s[i] << " ";
        }
        cout << s[k - 1] << endl;
    }
    //system("pause");
    return 0;
}                                 