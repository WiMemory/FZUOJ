/*
#include <iostream>
#include <algorithm>
using namespace std;
int heap[100000], hsize = 0, a[100000];

inline void insert(int n){
	int p,c=hsize;
	heap[hsize++]=n;
	//p为c的父节点
	p=(c-1)/2;
	//最后c为1或2
	while(c)
	{
		//小顶堆
		if(heap[p]>heap[c])
		{
			//通过三次异或，数值交换
			heap[p]^=heap[c];
			heap[c]^=heap[p];
			heap[p]^=heap[c];
			//沿着父节点不断往上判断交换
			c=p;
			p=(c-1)/2;
		}
		else return;
	}
}
inline void update(int p){
	int mt,l,r;
	//找出p的最小子节点
	l=2*p+1;
	r=2*p+2;
	if(l>=hsize&&r>=hsize)return;
	if(r>=hsize)
		mt=l;
	else
		mt=heap[l]<heap[r]?l:r;
	if(heap[p]>heap[mt]){
		//交换
		heap[p]^=heap[mt];
		heap[mt]^=heap[p];
		heap[p]^=heap[mt];
		//向下不断交换
		update(mt);
	}
}
inline int del(){
	//取出堆顶的值（最小值）
	int ret=heap[0];
	hsize--;
	//把堆尾的值放到堆顶
	heap[0]^=heap[hsize];
	heap[hsize]^=heap[0];
	heap[0]^=heap[hsize];
	//更新堆
	update(0);
	return ret;
}
int main(){
	int i,t,n,tcnt,ans,val;
	while(scanf("%d",&t)!=EOF)
	{
		//将输入的数据插入堆
		for(i=hsize=0;i<t;i++)
		{
			scanf("%d",&n);
			insert(n);
		}
		ans=1;tcnt=1;
		//出堆放入a[]
		for(i=0;i<t;i++)
			a[i]=del();
		val=a[0];
		//找出众数
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
		//找出众数
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