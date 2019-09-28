#include <iostream>
#include <algorithm>
using namespace std;
int n;              //小棒总数
int len;            //正方形边长
int parts;          //需要检查的组合组数
int sum;            //所有小棒的总长
int a[100];         //存储小棒相关信息
bool used[100];     //标记小棒是否使用

bool pt(int a, int b)
{
	return a > b;
}
/*
**	深度优先搜索
**  res:当前组合的木棒的长度
**  cpl:当前符合条件的组合的组数
**	level:搜索的起始深度
*/
bool dfs(int res, int cpl, int level)
{
	int i;
	if (cpl == parts)//三个组合边长都等于正方形边长
	{
		return true;
	}
	for (i = level; i < n; i++)
	{
		if (i && !used[i - 1] && a[i] == a[i - 1])//剪枝,当前元素和前一个元素相同且前一个元素未加入组合
			continue;
		if (used[i] ==  false)
		{
			if (res + a[i] < len)//继续查找下x个元素能和当前元素组合成等于边长
			{
				used[i] = true;
				if (dfs(res + a[i], cpl, i + 1))
					return true;
				used[i] = false;
			}
			else if (res + a[i] == len)//找到1组，继续查找后续分组，都成功才可以
			{
				used[i] = true;
				if (dfs(0, cpl + 1, 0))
					return true;
				used[i] = false;
			}
			if (res == 0)//在当前元素下,此组可以成功但查找下组失败,或是此组不可以成功组合,退出循环,返回失败
				break;
		}
	}
	return false;//当前组合直到扫描到末尾仍无法符合则向上层返回false
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
			//从大到小排列
			sort(a, a + n, pt);
			len = sum / 4;
			parts = 3;//只要前3组符合正方形边长，则最后1组必符合
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