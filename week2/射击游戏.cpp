#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        int s[500] = {0};
        int d[500][500] = {0};
        long long int sum = 0;
        s[1] = 1;
        for (int k = 2; k <= n; k++) {
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= i + 1; j++) {
                    d[i][j] = s[i];
                }
            }
            for (int i = 1; i < n; i++) {
                s[i] = 0;
            }
            for (int  j = 1; j < n; j++) {
                for (int i = 1; i < n; i++) {
                    s[j] += d[i][j];
                }
            }
            s[k] = 1;
        }
        for (int i = 1; i <= n; i++) {
            sum+= s[i];
        }
        cout << sum << endl;
    }
    return 0;
}                                 
