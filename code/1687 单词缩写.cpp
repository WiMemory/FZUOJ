#define gets(x) gets_s(x)
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1005];
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		memset(s, 0, sizeof(s));
		gets(s);
		int blag = 0, k = 0, len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] != ' ')    //当前是字母 
			{
				if (!blag)       //如果是第一个字母  输出这个字母 
				{
					cout << s[i];
					blag++;
				}
				else      //否则不输出 统计单词字母个数
				{
					if (i == len - 1)      //但是当为最后一个字母的时候就需要输出 
						cout << s[i];
					blag++;
				}
			}
			else     //当前为空格 
			{
				if (blag > 1)     //当前空格前面一位不是空格 并且单词字母个数不止一个 
				{
					cout << s[i - 1];    //把单词最后一位输出 
				}
				cout << s[i];    //空格也要一起输出 
				blag = 0;
			}
		}
		cout << endl;
	}
	return 0;
}