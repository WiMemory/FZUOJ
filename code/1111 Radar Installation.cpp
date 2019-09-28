#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
struct Pos {
	double x, y;
}island[1005];
struct Block {
	double left, right;
}block[1005];
//������ 
bool cmp(Block a, Block b) {
	if (a.right != b.right) return a.right < b.right;
	else return a.left > b.left;
}
int main() {
	double d;    //�״�뾶   
	int n, m;    //���ĸ��� �״���� 
	bool bo;     //�Ƿ�Υ�� 
	int c = 1;   //������ 
	while (~scanf("%d %lf", &n, &d) && n != 0 && d != 0) {
		bo = true;
		m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &island[i].x, &island[i].y);
			if (island[i].y > d) {//���С���뺣���ľ�����״�뾶���󣬾��޽� 
				bo = false;
			}
			//����С��ΪԲ�ģ��״�뾶 d Ϊ�뾶��Բ O �ں��������ҽ��� 
			block[i].left = (island[i].x - (double)sqrt(d*d - island[i].y*island[i].y));
			block[i].right = (island[i].x + (double)sqrt(d*d - island[i].y*island[i].y));
		}
		if (!bo) {
			printf("Case %d: -1\n", c++);//�޽���� -1 
		}
		else {
			std::sort(block, block + n, cmp);//���������� 
			double temp = -999999;
			for (int i = 0; i < n; i++) {
				if (block[i].left > temp) {//����ѡ������ 
					temp = block[i].right;
					m++;
				}
			}
			printf("Case %d: %d\n", c++, m);
		}
	}
}