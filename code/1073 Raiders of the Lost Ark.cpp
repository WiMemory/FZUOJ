#include<iostream>
using namespace std;
char m[11][11];
int nextstep[8][2] = { {1,0},{-1,0},{0,-1},{0,1},{2,2},{-2,2},{2,-2},{-2,-2} };
int x, y;
int sx, sy, xx, xy;
int ans;
void DFS(int nx, int ny, int d) {
	if (nx<1 || nx>x || ny<1 || ny>y) return;
	if (m[nx][ny] == 'W') return;
	if (m[nx][ny] == 'X') {
		if (ans > d || ans == 0) {
			ans = d;
		}
		return;
	}
	for (int i = 0; i < 8; i++) {
		m[nx][ny] = 'W';
		DFS(nx + nextstep[i][0], ny + nextstep[i][1], d + 1);
		m[nx][ny] = 'B';
	}
}
int main() {
	int n, i, j;
	cin >> n;
	while (n--) {
		ans = 0;
		cin >> x >> y;
		for (i = 1; i <= x; i++) {
			for (j = 1; j <= y; j++) {
				cin >> m[i][j];
				if (m[i][j] == 'S') {
					sx = i; sy = j;
				}
				else if (m[i][j] == 'X') {
					xx = i; xy = j;
				}
			}
		}
		DFS(sx, sy, 0);
		if (ans) cout << ans << endl;
		else cout << "NO ANSWER" << endl;
	}
}