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
			if (s[i] != ' ')    //��ǰ����ĸ 
			{
				if (!blag)       //����ǵ�һ����ĸ  ��������ĸ 
				{
					cout << s[i];
					blag++;
				}
				else      //������� ͳ�Ƶ�����ĸ����
				{
					if (i == len - 1)      //���ǵ�Ϊ���һ����ĸ��ʱ�����Ҫ��� 
						cout << s[i];
					blag++;
				}
			}
			else     //��ǰΪ�ո� 
			{
				if (blag > 1)     //��ǰ�ո�ǰ��һλ���ǿո� ���ҵ�����ĸ������ֹһ�� 
				{
					cout << s[i - 1];    //�ѵ������һλ��� 
				}
				cout << s[i];    //�ո�ҲҪһ����� 
				blag = 0;
			}
		}
		cout << endl;
	}
	return 0;
}