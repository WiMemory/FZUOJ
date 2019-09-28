#include<iostream>
#include<stack>
using namespace std;
char str[10005];
int main() {
	stack<char> s;
	int l, i;
	while (scanf("%s", str) != EOF) {
		l = strlen(str);
		for (i = 0; i < l; i++) {
			if (str[i] == '(') {
				s.push('(');
			}
			else {
				if (!s.empty()&&s.top() == '(') {
					s.pop();
				}
				else {
					s.push(')');
				}
			}
		}
		if (s.empty()) {
			printf("%s\n", str);
		}
		else {
			int size = s.size();
			int sum = 0;
			for (i = size - 1; i >= 0; i--) {
				str[i] = s.top();
				s.pop();
				if (str[i] == '(') {
					++sum;
				}
			}
			str[size] = '\0';
			printf("%s\n", str);
			for (i = 0; i < size - sum; i++) {
				printf("(");
			}
			for (i = 0; i < size - sum; i++) {
				printf(")");
			}
			for (i = 0; i < sum; i++) {
				printf("(");
			}
			for (i = 0; i < sum; i++) {
				printf(")");
			}
			printf("\n");
		}
	}
}