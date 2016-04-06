#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int count, Test;
    cin >> count;
    int result = 0;
    while (count--) {
        cin >> Test;
        int *num = new int[Test];
        for (int i = 0; i < Test; i++) {
            cin >> num[i];
        }
        sort(num, num + Test);
        for (int i = 0; i < Test - 1; i++) {
            result += num[i + 1] - num[i];
        }
        cout << result*2 << endl;
        result = 0;
    }
    return 0;
}                                 