#include<stdio.h>
#include<algorithm> //string���Ͳ���ֱ����scanf����,sort
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main() {
	map<string, int> mm;//int��������ڼ����ַ���
	string s;
	int m, n;
	register int i;
	while (scanf("%d", &n) != EOF) {
		getchar();
		for (i = 1; i <= n; i++) {
			cin >> s;
			sort(s.begin(), s.end());//�ֵ��еĵ��ʵ���ĸ����
			++mm[s];
		}
		map<string, int>::iterator mi;

		scanf("%d", &m);
		getchar();
		for (i = 1; i <= m; i++) {
			cin >> s;
			sort(s.begin(), s.end());//�ֵ��еĵ��ʵ���ĸ����
			mi = mm.find(s);
			if (mi != mm.end())
				printf("%d\n", mi->second);
			else
				printf("0");
		}

	}
	return 0;
}