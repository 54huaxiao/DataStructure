#include<iostream>
using namespace std;
int main() {
	int stage(int);
	int count, num;
	cin >> count;
	while (count--) {
		cin >> num;
		cout << stage(num) << endl;
	}
	return 0;
}
int stage(int numbers) {
	if (numbers == 2) return 2;
	if (numbers == 1) return 1;
	else return stage(numbers - 1) + stage(numbers - 2);
}                                
