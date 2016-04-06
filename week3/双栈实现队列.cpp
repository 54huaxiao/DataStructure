#include<stack>
using std::stack;
class Queue
{
public:
	bool IsEmpty() const {
		return firstStack.size() == 0;
	}
	int &front() {
		while (!firstStack.empty()) {
			secondStack.push(firstStack.top());
			firstStack.pop();
		}
		return secondStack.top();
	}
	void push(int a) {
		firstStack.push(a);
	}
	void pop() {
		while (!firstStack.empty()) {
			secondStack.push(firstStack.top());
			firstStack.pop();
		}
		secondStack.pop();
		while (!secondStack.empty()) {
			firstStack.push(secondStack.top());
			secondStack.pop();
		}
	}
private:
	stack<int > firstStack;
	stack<int > secondStack;
};                                 
