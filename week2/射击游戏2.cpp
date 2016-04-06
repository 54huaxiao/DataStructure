#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T, n, i, j, k, diff, index, num, a[15], b[15];
    cin >> T;
    while (T--) {
        stack<int> sta;
        index = 0;
        sta.push(1);  //  1首先进栈 
        num = 1;
        for (i = 0; i < 10; i++) {
            cin >> a[i];
            while (a[i] >= num) {
                sta.push(num++);
            }  //  当输入的数大于当前数时，说明要输出的数还未进栈 
            if (a[i] == sta.top()) {
                b[index++] = sta.top();
                sta.pop();
            }  //  将模拟栈输出的顺序存到数组b中 
            
        }
        for (i = 0; i < 10; i++)
        if (a[i] != b[i]) {
            cout << "No" << endl;
            break;
        }  //  若a与b中有元素不同，说明输出顺序不同，即不满足栈输出顺序 
        if (i == 10) cout << "Yes" << endl;
    }
}                                 
