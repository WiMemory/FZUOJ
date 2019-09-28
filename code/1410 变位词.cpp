#include<stdio.h>
#include<algorithm> //string类型不能直接用scanf读入,sort
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main() {
	map<string, int> mm;//int这个数组存第几个字符串
	string s;
	int m, n;
	register int i;
	while (scanf("%d", &n) != EOF) {
		getchar();
		for (i = 1; i <= n; i++) {
			cin >> s;
			sort(s.begin(), s.end());//字典中的单词的字母排序
			++mm[s];
		}
		map<string, int>::iterator mi;

		scanf("%d", &m);
		getchar();
		for (i = 1; i <= m; i++) {
			cin >> s;
			sort(s.begin(), s.end());//字典中的单词的字母排序
			mi = mm.find(s);
			if (mi != mm.end())
				printf("%d\n", mi->second);
			else
				printf("0");
		}

	}
	return 0;
}