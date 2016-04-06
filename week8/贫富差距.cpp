// Problem#: 16361
// Submission#: 4152811
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;
int  a[1000003];
int main() {
    int t, n, k;
    int i, j, x1, x2, temp1, temp2;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        if (k%2 != 0) {
            temp1 = (k-1)/2;
            x2 = a[temp1];
        x1 = a[n-1-temp1];
        } else {
            temp2 = k/2;
            x2 = (a[temp2-1]+a[temp2])/2;
            x1 = (a[n-1-temp2]+a[n-temp2])/2;
        }
        cout << x1-x2 << endl;
    }
}                                 