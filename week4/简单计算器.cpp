#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <cctype>
using std::string;
using std::queue;
using std::cin;
using std::cout;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else {
        return false;
    }
}
void getNumberAndOperator(string& src, queue<double>& number, queue<char>& op) {
    int len = src.length();
    char num[100];
    int i = 0;
    while (i < len && isspace(src[i])) i++;
    if (i < len && (src[i] == '-' || isdigit(src[i]))) {
        int j = 0;
        if (src[i] == '-') {    // first minus
            num[j++] = src[i++];
            while (i < len && isspace(src[i])) i++;
        }
        if (src[i] == '-') {    // two minus
            j--;
            i++;
        }
        while (i < len && isdigit(src[i])) {
            num[j++] = src[i++];
        }
        num[j] = '\0';
        if (i < len && src[i] == '.') {
            num[j++] = src[i++];
            while (i < len && isdigit(src[i])) {
                num[j++] = src[i++];
            }
            num[j] = '\0';
        }
        number.push(atof(num));
    }
    while (i < len) {
        while (i < len && isspace(src[i])) i++;
        if (i < len && isOperator(src[i])) {
            op.push(src[i++]);
        }
        while (i < len && isspace(src[i])) i++;
        if (i < len && (isdigit(src[i]) || src[i] == '-') ) {
            int j = 0;
            if (src[i] == '-') {
                num[j++] = src[i++];
                while (i < len && isspace(src[i])) i++;
            }
            while (i < len && isdigit(src[i])) {
                num[j++] = src[i++];
            }
            num[j] = '\0';
            if (i < len && src[i] == '.') {
                num[j++] = src[i++];
                while (i < len && isdigit(src[i])) {
                    num[j++] = src[i++];
                }
                num[j] = '\0';
            }
            number.push(atof(num));
        }
    }
}

double compute(queue<double>& number, queue<char>& op) {
    if (number.empty()) {
        return 0;
    }
    // getNumberAndOperator(src);
    char op1, op2;
    double num1 = 0, num2 = 0;
    num1 = number.front();
    number.pop();
    while (!op.empty() && (op.front() == '*' || op.front() == '/')) {
        op1 = op.front();
        op.pop();
        if ('*' == op1) {
            num1 *= number.front();
            number.pop();
        } else if ('/' == op1) {
            num1 /= number.front();
            number.pop();
        }
    }
    while (!op.empty()) {
        op1 = op.front();
        op.pop();
        num2 = number.front();
        number.pop();
        while (!op.empty() && (op.front() == '*' || op.front() == '/')) {
            op2 = op.front();
            op.pop();
            if (op2 == '*') {
                num2 *= number.front();
                number.pop();
            } else if (op2 == '/') {
                num2 /= number.front();
                number.pop();
            }
        }
        ('+' == op1) ? num1 += num2 : num1 -= num2;
    }
    // printf("%.3lf\n", num1);
    while (!number.empty()) {
        number.pop();
    }
    while (!op.empty()) {
        op.pop();
    }
    return num1;
}

double preCompute(string& input) {
    double ans;
    size_t i;
    while ((i = input.find("(")) != string::npos) {
        size_t j;
        for (j = i + 1; j < input.length(); j++) {
            if (input[j] == ')') {
                break;
            } else if (input[j] == '(') {
                i = j;
            }
        }
        if (j < input.length()) {
            char temp[100];
            string sub = input.substr(i + 1, j - i - 1);
            ans = preCompute(sub);
            // cout << sub << " == " << ans << '\n';   // print for detection
            snprintf(temp, sizeof(temp), "%lf", ans);
            input.replace(i, j - i + 1, temp);
        }
    }
    queue<double> preNum;
    queue<char> preOp;
    getNumberAndOperator(input, preNum, preOp);
    ans = compute(preNum, preOp);
    // cout << input << " == " << ans << '\n';
    return ans;
}

int main() {
    string input;
    double ans;
    int t;
    scanf("%d", &t);
    getline(cin, input);
    while (t-- > 0) {
        getline(cin, input);
        ans = preCompute(input);
        printf("%.3lf\n", ans);
    }
    return 0;
}                                 
