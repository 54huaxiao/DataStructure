#include<iostream>
using namespace std;
int main() {
    int digitsum(int);
    int count, num;
    int i;
    cin >> count;
    while (count--) {
        cin >> num;
        for (i = (num > 100 ? num-100:0); i < num; i++) {
            if (digitsum(i) == num) {
                cout << i << endl;
                break;
            }
            else continue;
        }
        if (i == num) cout << "0\n";
    }
    return 0;
}
int digitsum(int k) {
    int temp = k, result = 0;
    while (temp) {
        result += temp % 10;
        temp = temp / 10;
    }
    result += k;
    return result;
}                                 