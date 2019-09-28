#include<iostream>
#include<set>
using namespace std;
int num[505];
set<int> s;
set<int>::iterator it;
bool isin(int a) {
	int total = 0, muti = 1;
	int num;
	//条件一，需要判断是否偶数
	if (a % 2 == 0) {
		//否则 11 / 2 = 5，即所有数字都会被认为符合条件一
		it = s.find(a / 2);
		if (it != s.end()) {
			return true;
		}
	}
	//条件二
	while (a) {
		num = a % 10;
		if (num == 0) {
			return false;
		}
		total += num;
		muti *= num;
		a /= 10;
	}
	if (total != muti) {
		return false;
	}
	return true;
}
//打表初始化
void init() {
	int i, j;
	for (i = 1, j = 1; j <= 500; i++) {
		if (isin(i)) {
			num[j++] = i;
			s.insert(set<int>::value_type(i));
		}
	}
}
int main() {
	int N, k;
	cin >> N;
	init();
	while (N--) {
		cin >> k;
		cout << num[k] << endl;
	}
}