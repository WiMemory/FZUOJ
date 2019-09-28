#include <stdio.h>
#include <string.h>
//把m转化为n进制,放入ret[]中
void conv(int m, int n, char ret[]) {
	int k,l,i;
	int arr[50];
	int count;
	count = 0;
	k=m;
	while (1) {
		l = k%n;
		if (k == 0) break;
		if (l>=10)
			arr[count] = 'A'+l-10;
		else arr[count] = l + '0';
		k /= n;
		count++;
	}
	for (i=0;i<count;i++)
		ret[i] = arr[count-i-1];
	ret[i] = '\0';
	return;
}
bool IsPig(char str[]) {
	int len;
	int i;
	len = strlen(str);
	for (i=0;i<len/2;i++) {
		if (str[i] != str[len-i-1])
			return false;
	}
	return true;
}
int main() {
	int i,n;
	int arr[300];
	char ret[50];
	char num[50];
	for (i=0;i<300;i++)
		arr[i] = (i+1)*(i+1);
	while (scanf("%d", &n) != EOF) {
		for(i=0;i<300;i++) {
			conv(arr[i], n, ret);
			conv(i+1, n, num);
			if (IsPig(ret))
				printf("%s %s\n", num, ret);
		}
	}
	return 0;
}