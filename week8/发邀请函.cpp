// Problem#: 16362
// Submission#: 4152245
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 16355
// Submission#: 4152237
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
#define MAX 100001
int main() {
    int count, M, N;
    int F[21], H[MAX];
    cin >> count;
    while (count--) {
        int max = 0, flag = 0;
        cin >> M >> N;
        for (int i = 0; i < M; i++) {
            cin >> F[i];
            if (F[i] >= max) max = F[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> H[i];
            if (H[i] == max) flag = i;
        }
        cout << flag * 50 << endl;
    }
    return 0;
}                                 