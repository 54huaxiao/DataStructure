#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
int num[26];
int T, n, total, index;
cin >> T;  //T个测例
for (; T > 0; T--) {
cin >> n;
for (int i = 0; i < 26; i++)
num[i] = 0;           //初始化置空
num[0] = 1;                //第一个肯定放1
index = 1;
for (int i = 2; i <= n; i++) {
for (total = 0; total < i;) {  //total用来表示当前第几个空牌位
if (num[index] == 0)
total++;
if (total == i)
break;
if (index == n - 1)      //到达数组尾部跳回头部
index = 1;
else index++;
}
num[index] = i;           //放牌
}
for (int i = 0; i < n; i++) {
cout << num[i] << ' ';
}
cout << endl;
}
}                                 
