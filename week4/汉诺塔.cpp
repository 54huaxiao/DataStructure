#include<iostream>
using namespace std;
int main() {
    void hannota(int, int, int, int);
    int count, num;
    cin >> count;
    while (count--) {
        cin >> num;
        hannota(num, 1, 3, 2);
    }
    return 0;
}
void hannota(int count, int start, int finish, int temp) {
    if (count > 0) {
        hannota(count - 1, start, temp, finish);
        cout << "move disk " << count << " from peg " << start << " to peg " << finish << endl;
        hannota(count - 1, temp, finish, start);
    }
}                                 
