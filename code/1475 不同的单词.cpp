/*
	map的用法：https://blog.csdn.net/flqbestboy/article/details/8184484
*/
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main()
{
	int n;
	string s;
	map<string, int>m;
	while (cin >> n)
	{
		getchar();//储存回车，也可以没有这个语句，因为使用了cin会把回车符过滤掉

		m.clear();//将其清空
		while (n--)
		{
			scanf("%s", s);
			for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);//统一成小写，大写是toupper
			m[s]++;//会将重复的字符过滤掉，然后再加起来
		}
		cout << m.size() << endl;//输出其大小

	}
	return 0;
}