#include <iostream>
#include <string>
using namespace std;

void gan(const string& n,const string& m) {
    if (m.size() == 1) {
        cout << n << m << endl;
    }
    else {
        for (int i = 0; i < m.size(); i++) {
            gan(string(n + m[i]), string(m).erase(i, 1));
        }
    }
}
int main() {
    int N, n;
    string t;
    cin >> N;
    while (N--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            t += i + '0';
        }
        gan("", t);
        t = "";
    }
}                               
