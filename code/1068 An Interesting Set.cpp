#include<iostream>
#include<set>
using namespace std;
int num[505];
set<int> s;
set<int>::iterator it;
bool isin(int a) {
	int total = 0, muti = 1;
	int num;
	//����һ����Ҫ�ж��Ƿ�ż��
	if (a % 2 == 0) {
		//���� 11 / 2 = 5�����������ֶ��ᱻ��Ϊ��������һ
		it = s.find(a / 2);
		if (it != s.end()) {
			return true;
		}
	}
	//������
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
//����ʼ��
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