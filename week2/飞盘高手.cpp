#include<iostream>
#include<queue>
using namespace std;
int main() {
int count, num;
queue<int > q;
cin >> count;
while (count--) {
cin >> num;
for (int i = 0; i < num; i++) {
q.push(i + 1);
}
while (q.size() > 2) {
cout << q.front() << " ";
q.pop();
q.push(q.front());
q.pop();
}
if (q.size() == 2) {
cout << q.front() << " ";
q.pop();
}
cout << q.front() << " " << endl;
q.pop();
}
return 0;
}                                 
