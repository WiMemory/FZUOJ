/*
	map���÷���https://blog.csdn.net/flqbestboy/article/details/8184484
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
		getchar();//����س���Ҳ����û�������䣬��Ϊʹ����cin��ѻس������˵�

		m.clear();//�������
		while (n--)
		{
			scanf("%s", s);
			for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);//ͳһ��Сд����д��toupper
			m[s]++;//�Ὣ�ظ����ַ����˵���Ȼ���ټ�����
		}
		cout << m.size() << endl;//������С

	}
	return 0;
}