#include<iostream>
using namespace std;
char url[65];
char Protocol[7], Host[65], Port[6], Path[65];

int main() {
	int n, i = 0, j, k;
	scanf("%d", &n);
	while (n--) {
		memset(url, '\0', sizeof(url));
		memset(Protocol, '\0', sizeof(Protocol));
		memset(Host, '\0', sizeof(Host));
		memset(Port, '\0', sizeof(Port));
		memset(Path, '\0', sizeof(Path));
		++i;
		scanf("%s", url);
		for (j = 0; j < 7; j++) {
			if (url[j] == ':') {
				break;
			}
			Protocol[j] = url[j];
		}
		for (j += 3, k = j; j < 65; j++) {
			if (url[j] == '\0' || url[j] == ':' || url[j] == '/') {
				break;
			}
			Host[j-k] = url[j];
		}
		if (url[j] == ':') {
			for (++j, k = j; j < 65; j++) {
				if (url[j] == '\0' || url[j] == '/') {
					break;
				}
				Port[j - k] = url[j];
			}
		}
		if (url[j] == '/') {
			for (++j, k = j; j < 65; j++) {
				if (url[j] == '\0') {
					break;
				}
				Path[j - k] = url[j];
			}
		}
		printf("URL #%d\nProtocol = %s\nHost     = %s\nPort     = ", i, Protocol, Host);
		if (Port[0] == '\0') {
			printf("<default>\nPath     = ");
		}
		else {
			printf("%s\nPath     = ", Port);
		}
		if (Path[0] == '\0') {
			printf("<default>\n\n");
		}
		else {
			printf("%s\n\n", Path);
		}
	}
	return 0;
}