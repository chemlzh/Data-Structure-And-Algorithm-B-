#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
long n, flen;
char formula[800], c;
stack<int> num;
stack<char> op;

inline long priority(char ch) {
	switch (ch) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	case '(': case ')': return 0;
	default: return -1;
	}
}

inline long calcnum(long num1, long num2, char ch) {
	switch (ch) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	case '^': return (long)pow(num1, num2);
	default: return -1;
	}
}

inline long calc() {
	long len = strlen(formula), pos = 0, tnum, num1, num2;
	char tmp[20], ch;
	while (pos<len) {
		sscanf(formula + pos, "%s", tmp), pos += strlen(tmp) + 1;
		if ((tmp[0] >= '0') && (tmp[0] <= '9')) {
			tnum = 0;
			for (long i = 0; i < strlen(tmp); i++) tnum = tnum * 10 + tmp[i] - '0';
			num.push(tnum);
		}
		else if ((tmp[0] == '-') && (tmp[1] >= '0') && (tmp[1] <= '9')) {
			tnum = 0;
			for (long i = 1; i < strlen(tmp); i++) tnum = tnum * 10 + tmp[i] - '0';
			num.push(-tnum);
		}
		else if ((tmp[0] == '+') || (tmp[0] == '-') || (tmp[0] == '*') || (tmp[0] == '/') || (tmp[0] == '^')) {
			if (op.empty()) op.push(tmp[0]);
			else {
				ch = op.top();
				if (priority(ch) < priority(tmp[0])) op.push(tmp[0]);
				else {
					while (priority(ch) >= priority(tmp[0])) {
						num1 = num.top(), num.pop(), num2 = num.top(), num.pop();
						op.pop();
						num.push(calcnum(num2, num1, ch));
						if (op.empty()) break;
						else ch = op.top();
					}
					op.push(tmp[0]);
				}
			}
		}
		else if (tmp[0] == '(') op.push('(');
		else if (tmp[0] == ')') {
			while (op.top() != '(') {
				num1 = num.top(), num.pop(), num2 = num.top(), num.pop();
				ch = op.top(), op.pop();
				num.push(calcnum(num2, num1, ch));
			}
			op.pop();
		}
	}
	while (!op.empty()) {
		num1 = num.top(), num.pop(), num2 = num.top(), num.pop();
		ch = op.top(), op.pop();
		num.push(calcnum(num2, num1, ch));
	}
	return num.top();
}

int main() {
	scanf("%ld", &n), c = getchar();
	for (long i = 0; i < n; i++) {
		memset(formula, 0, sizeof(formula)), flen = 0;
		while ((c = getchar()) != EOF) {
			if ((c == '\n') || (c == '\r')) break;
			formula[flen++] = c;
		}
		printf("%ld\n", calc());
	}
}