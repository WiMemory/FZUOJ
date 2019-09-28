#include <iostream>
#include <stdlib.h>
using namespace std;
char maze[8][8];
int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };//��������
int n, m, t, step, remain, destx, desty;
bool found;
void dfs(int ic, int jc, int tc)
{
	if (tc == t && ic == destx && jc == desty)
		found = true;
	if (found) return;
	int v = t - tc - abs(destx - ic) - abs(desty - jc);//����ż�Լ�֦
	if ((abs(destx - ic) + abs(desty - jc)) % 2 != (t - tc) % 2) return;//if(v<0||v&1)return;
	for (int d = 0; d < 4; ++d)//���ĸ��������
	{
		int ki = ic + dir[d][0];
		int kj = jc + dir[d][1];
		if (ki >= 0 && ki < n&&kj >= 0 && kj < m&&maze[ki][kj] != 'X')
		{
			maze[ki][kj] = 'X';
			dfs(ki, kj, tc + 1);//��ȱ���
			maze[ki][kj] = '.';//���ݳɵ�
		}
	}
}
int main()
{
	while (cin >> n >> m >> t)
	{
		if (n == 0 && m == 0 && t == 0)break;
		step = 0; remain = 0;
		found = false;
		int icur, jcur;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 'S')
				{
					icur = i; jcur = j;
				}
				else if (maze[i][j] == 'D')
				{
					++remain;
					destx = i; desty = j;
				}
				else if (maze[i][j] == '.')++remain;
			}
		maze[icur][jcur] = 'X';
		//������ߵĸ���remain����ʱ��t��϶��޷��ɹ�����
		if (remain >= t)
			dfs(icur, jcur, 0);
		if (found)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}