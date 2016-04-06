// Problem#: 16360
// Submission#: 4151185
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;

int main() {
    int count, num;
    int a[1001];
    cin >> count;
    while (count--) {
        cin >> num;
        for (int i = 0; i < num; i++)
            cin >> a[i];
        int min;
        int temp;
        for (int i = 0; i < num - 1; i++) {
            min = i;
            for (int j = i + 1; j < num; j++) {
                if (a[min] > a[j])
                    min = j;
            }
            if (min != i) {
                temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
            for (int k = 0; k < num-1; k++)
                cout << a[k] << " ";
            cout << a[num-1] << endl;
        }
    }
    return 0;
}                                 