#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string a, string b) {
    return a + b < b + a;
}
int main() {
    bool cmp(string, string);
    vector<string > str;
    string sub;
    int count, T;
    cin >> count;
    while (count--) {
        cin >> T;
        while (T--) {
            cin >> sub;
            str.push_back(sub);
        }
        sort(str.begin(), str.end(), cmp);
        for (int i = 0; i < str.size(); i++) {
            cout << str[i];
        }
        cout << endl;
        str.clear();
    }
    return 0;
}                                 