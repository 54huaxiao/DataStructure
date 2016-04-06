// Problem#: 16580
// Submission#: 4215106
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, i, k, j, l;
    map<int, string> dic;
    cin >> n;
    string s;
    cin >> s;
    for (i = 0; i < n; i++) {
        dic[i] = s[i];
    }
    string sb;
    cin >> sb;
    l = n;
    n = sb.length();
    for (j = 0; j < n; j++) {
        if (sb[j] == '0' && sb[j-1] == '-') {
            int sum = 0;
            int m[4];
            dic[i] = "";
            for (k = j-1; k != -1; k--) {
                if (sb[k] == '0' && sb[k-1] == '-') break;
                if (sb[k] == '-' || k == 0) {
                    if (k == 0) {
                        m[sum] = sb[k]-'0';
                        sum++;
                    }
                    int su = 0;
                    for (int p = sum-1; p >= 0; p--) {
                        su = su*10 + m[p];
                    }
                    if (su != 0) {
                        dic[i] = dic[su-1]+dic[i];
                        su = 0;
                        sum = 0;
                    }
                }
                else {
                    m[sum] = sb[k] - '0';
                    sum++;
                }
            }
            if (l != i && dic[i] != "") cout << " ";
            cout << dic[i];
            if (dic[i] != "") i++;
        }
    }
    cout << endl;
    return 0;
}                                 