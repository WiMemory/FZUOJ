# Problem 1046 Tempter of the Bone

### Accept: 669    Submit: 1846 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

The doggie found a bone in an ancient maze, which fascinated him a lot. However, when he picked it up, the maze began to shake, and the doggie could feel the ground sinking. He realized that the bone was a trap, and he tried desperately to get out of this maze.

The maze was a rectangle with sizes N by M. There was a door in the maze. At the beginning, the door was closed and it would open at the T-th second for a short period of time (less than 1 second). Therefore the doggie had to arrive at the door on exactly the T-th second. In every second, he could move one block to one of the upper, lower, left and right neighboring blocks. Once he entered a block, the ground of this block would start to sink and disappear in the next second. He could not stay at one block for more than one second, nor could he move into a visited block. Can the poor doggie survive? Please help him.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The input consists of multiple test cases. The first line of each test case contains three integers N, M, and T (1 < N, M < 7; 0 < T < 50), which denote the sizes of the maze and the time at which the door will open, respectively. The next N lines give the maze layout, with each line containing M characters. A character is one of the following:

'X': a block of wall, which the doggie cannot enter;

 

'S': the start point of the doggie;

 

'D': the Door; or

'.': an empty block.

The input is terminated with three 0's. This test case is not to be processed.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 4 4 5
> S.X.
> ..X.
> ..XD
> ....
> 3 4 5
> S.X.
> ..X.
> ...D
> 0 0 0

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> NO
>
> YES

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

ZOJ 2110

## 解决方案

运用深度遍历的方法，配合**剪枝**（即按照一定条件提前结束某些不必要的遍历）、回溯即可

剪枝条件1.如果可走的格子remain少于时间t则肯定无法成功逃脱

剪枝条件2.奇偶判断

1 0 0 0 0

0 0 0 0 0

0 0 0 0 0

0 0 0 0 1

假设起点为左上角的1 终点为右下角的1 则按照最短路径需要时间t（7，奇数，垂直往下走3，水平往右走4），无论如何绕路，最终到达终点的时间T的奇偶性一定和最小时间t一致（奇数）。

```cpp
#include <iostream>
#include <stdlib.h>
using namespace std;
char maze[8][8];
int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };//遍历方向
int n, m, t, step, remain, destx, desty;
bool found;
void dfs(int ic, int jc, int tc)
{
	if (tc == t && ic == destx && jc == desty)
		found = true;
	if (found) return;
	int v = t - tc - abs(destx - ic) - abs(desty - jc);//据奇偶性剪枝
	if ((abs(destx - ic) + abs(desty - jc)) % 2 != (t - tc) % 2) return;//if(v<0||v&1)return;
	for (int d = 0; d < 4; ++d)//从四个方向遍历
	{
		int ki = ic + dir[d][0];
		int kj = jc + dir[d][1];
		if (ki >= 0 && ki < n&&kj >= 0 && kj < m&&maze[ki][kj] != 'X')
		{
			maze[ki][kj] = 'X';//走过的格子消失（墙）
			dfs(ki, kj, tc + 1);//深度遍历
			maze[ki][kj] = '.';//回溯成点
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
		//如果可走的格子remain少于时间t则肯定无法成功逃脱
		if (remain >= t)
			dfs(icur, jcur, 0);
		if (found)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
```

