/*
#include <iostream>
#include <algorithm>
using namespace std;
int heap[100000], hsize = 0, a[100000];

inline void insert(int n){
	int p,c=hsize;
	heap[hsize++]=n;
	//pΪc�ĸ��ڵ�
	p=(c-1)/2;
	//���cΪ1��2
	while(c)
	{
		//С����
		if(heap[p]>heap[c])
		{
			//ͨ�����������ֵ����
			heap[p]^=heap[c];
			heap[c]^=heap[p];
			heap[p]^=heap[c];
			//���Ÿ��ڵ㲻�������жϽ���
			c=p;
			p=(c-1)/2;
		}
		else return;
	}
}
inline void update(int p){
	int mt,l,r;
	//�ҳ�p����С�ӽڵ�
	l=2*p+1;
	r=2*p+2;
	if(l>=hsize&&r>=hsize)return;
	if(r>=hsize)
		mt=l;
	else
		mt=heap[l]<heap[r]?l:r;
	if(heap[p]>heap[mt]){
		//����
		heap[p]^=heap[mt];
		heap[mt]^=heap[p];
		heap[p]^=heap[mt];
		//���²��Ͻ���
		update(mt);
	}
}
inline int del(){
	//ȡ���Ѷ���ֵ����Сֵ��
	int ret=heap[0];
	hsize--;
	//�Ѷ�β��ֵ�ŵ��Ѷ�
	heap[0]^=heap[hsize];
	heap[hsize]^=heap[0];
	heap[0]^=heap[hsize];
	//���¶�
	update(0);
	return ret;
}
int main(){
	int i,t,n,tcnt,ans,val;
	while(scanf("%d",&t)!=EOF)
	{
		//����������ݲ����
		for(i=hsize=0;i<t;i++)
		{
			scanf("%d",&n);
			insert(n);
		}
		ans=1;tcnt=1;
		//���ѷ���a[]
		for(i=0;i<t;i++)
			a[i]=del();
		val=a[0];
		//�ҳ�����
		for(i=0;i<t-1;i++)
		{
			if(a[i]==a[i+1])
				tcnt++;
			else
			{
				if(tcnt>ans){ans=tcnt;val=a[i-1];}
				tcnt=1;
			}
		}
		if(tcnt>ans){ans=tcnt;val=a[t-1];}
		printf("%d\n",val);
	}
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];

int main(){
	int i,t,tcnt,ans,val;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a, a + t);
		ans=1;tcnt=1;
		val=a[0];
		//�ҳ�����
		for(i=0;i<t-1;i++)
		{
			if(a[i]==a[i+1])
				tcnt++;
			else
			{
				if(tcnt>ans){ans=tcnt;val=a[i-1];}
				tcnt=1;
			}
		}
		if(tcnt>ans){ans=tcnt;val=a[t-1];}
		printf("%d\n",val);
	}
	return 0;
}