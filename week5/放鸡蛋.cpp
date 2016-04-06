#include <iostream>
#include <string>
using namespace std;

int list[300];

void gan(int n,int m, int t) {
    if (n == 0) {
        for (int i = 0; i < t; i++) {
            cout << list[i];
        }
        for (int i = t; t < m; t++) {
            cout << 0;
        }
        cout << endl;
        return;
    }
    for (int i = n; i >= n / (m-t); i--) {
        if (t == 0 || list[t - 1] >= i) {
            list[t] = i;
            gan(n - i, m, t + 1);
        }
    }
}
int main() {
    int N, n, m;
    cin >> N;
    while (N--) {
        cin >> n >> m;
        for (int i = 0; i < 300; i++) {
            list[i] = 0;
        }
        gan(n, m, 0);
    }
}                             
