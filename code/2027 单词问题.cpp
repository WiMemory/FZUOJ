#include<iostream>
#include<map>
#include<cstring>
using namespace std;
char str[105];
char word[105];
int main() {
	int i, len, j;
	map<string, int> m;
	map<string, int>::iterator it;
	while (scanf("%s", str) != EOF) {
		len = strlen(str);
		j = 0;
		for (i = 0; i <= len; i++) {
			if (str[i] >= 'A'&&str[i] <= 'Z' || str[i] >= 'a'&&str[i] <= 'z') {
				word[j] = str[i];
				++j;
			}
			//注意此处应该判断单词是否存在，否则出现多个非字母字符时打印多个换行符
			else if(j > 0){
				word[j] = '\0';
				j = 0;
				it = m.find(word);
				if (it == m.end()) {
					m.insert(map<string, int>::value_type(word, 1));
					printf("%s\n", word);
				}
			}
		}
		m.clear();
	}
}