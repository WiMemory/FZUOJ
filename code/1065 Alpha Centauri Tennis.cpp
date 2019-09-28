#define gets(x) gets_s(x)
#include<iostream>
using namespace std;
char str[1000005];
int main() {
	while (gets(str)) {
		cout << str[strlen(str) - 1] << endl;
	}
}