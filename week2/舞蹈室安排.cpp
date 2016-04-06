#include<iostream>
using namespace std;
struct Time {
	int b, e;
};
int main() {
	int n, m, i, j, count;
	Time T[150];
	Time temp;
	cin >> n;
	for (; n > 0; n--) {
		cin >> m;
		for (j = 0; j < m; j++) {
			cin >> T[j].b >> T[j].e;
		}
		for (j = 0; j < m - 1; j++) {
			for (i = 0; i < m - 1 - j; i++) {
				if (T[i].e >= T[i + 1].e) {
					temp = T[i];
					T[i] = T[i + 1];
					T[i + 1] = temp;
				}
			}
		}
		for (i = 0, count = 0; i < m; i++) {
			if (i == 0) {
				count++;
				temp = T[i];
				continue;
			}
			if (T[i].b>temp.e) {
				temp = T[i];
				count++;
			}
		}
		cout << count << endl;
	}
}                                 
