// Problem#: 16579
// Submission#: 4180566
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int main() {
    int n, a[11];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int temp = 0;
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n-1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << endl;
    if (n % 2 == 0) cout << (a[n / 2 - 1] + a[n / 2]) / 2;
    else cout << a[n / 2];
    //system("pause");
    return 0;
}                                 