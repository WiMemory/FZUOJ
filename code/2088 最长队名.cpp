#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string name;
int main() {
	int T, n, i;
	cin >> T;
	vector<string> str;
	vector<string>::iterator it;
	while (T--) {
		str.clear();
		cin >> n;
		getchar();
		for (i = 0; i < n; i++) {
			cin >> name;
			str.push_back(name);
		}
		sort(str.begin(), str.end());
		for (it = str.begin(); it != str.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
}