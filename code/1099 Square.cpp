#include <iostream>
#include <algorithm>
using namespace std;
int n;              //С������
int len;            //�����α߳�
int parts;          //��Ҫ�����������
int sum;            //����С�����ܳ�
int a[100];         //�洢С�������Ϣ
bool used[100];     //���С���Ƿ�ʹ��

bool pt(int a, int b)
{
	return a > b;
}
/*
**	�����������
**  res:��ǰ��ϵ�ľ���ĳ���
**  cpl:��ǰ������������ϵ�����
**	level:��������ʼ���
*/
bool dfs(int res, int cpl, int level)
{
	int i;
	if (cpl == parts)//������ϱ߳������������α߳�
	{
		return true;
	}
	for (i = level; i < n; i++)
	{
		if (i && !used[i - 1] && a[i] == a[i - 1])//��֦,��ǰԪ�غ�ǰһ��Ԫ����ͬ��ǰһ��Ԫ��δ�������
			continue;
		if (used[i] ==  false)
		{
			if (res + a[i] < len)//����������x��Ԫ���ܺ͵�ǰԪ����ϳɵ��ڱ߳�
			{
				used[i] = true;
				if (dfs(res + a[i], cpl, i + 1))
					return true;
				used[i] = false;
			}
			else if (res + a[i] == len)//�ҵ�1�飬�������Һ������飬���ɹ��ſ���
			{
				used[i] = true;
				if (dfs(0, cpl + 1, 0))
					return true;
				used[i] = false;
			}
			if (res == 0)//�ڵ�ǰԪ����,������Գɹ�����������ʧ��,���Ǵ��鲻���Գɹ����,�˳�ѭ��,����ʧ��
				break;
		}
	}
	return false;//��ǰ���ֱ��ɨ�赽ĩβ���޷����������ϲ㷵��false
}

int main()
{
	int N;
	while (cin >> N)
	{
		while (N--)
		{
			sum = 0;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
				sum += a[i];
				used[i] = false;
			}
			//�Ӵ�С����
			sort(a, a + n, pt);
			len = sum / 4;
			parts = 3;//ֻҪǰ3����������α߳��������1��ط���
			if (sum % 4 == 0 && dfs(0, 0, 0))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}