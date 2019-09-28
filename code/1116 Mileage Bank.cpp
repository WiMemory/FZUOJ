#include<iostream>
#include<string>
using namespace std;
int main() {
	int mile, total = 0;
	char type;
	string str;
	char *p;
	while (getline(cin, str) && str != "#") {
		if (str == "0") {
			cout << total << endl;
			total = 0;
			continue;
		}
		p = &str[0];
		sscanf(p, "%*s%*s%d%*c%c", &mile, &type);
		switch (type) {
		case 'Y':
			if (mile > 500) total += mile;
			else total += 500;
			break;
		case 'B':
			total += mile;
			if (mile % 2) mile += 1;
			total += mile / 2;
			break;
		case 'F':
			total += mile * 2;
			break;
		}
	}
	return 0;
}