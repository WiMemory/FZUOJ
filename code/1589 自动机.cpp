#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int N, Commandnum;
	int ID;
	deque<double>d[10000];
	double val;
	char Command[5];
	register int i, j;
	while (scanf("%d%d", &N, &Commandnum) != EOF)
	{
		for (i = 0; i < Commandnum; i++)
		{
			scanf("%s", Command);
			if (strcmp(Command, "INIT") == 0)
			{
				for (j = 0; j < 10000; j++)
				{
					d[j].clear();
				}
			}
			if (strcmp(Command, "PUSH") == 0)
			{
				scanf("%d%lf", &ID, &val);
				d[ID].push_back(val);
			}
			if (strcmp(Command, "POP") == 0)
			{
				scanf("%d", &ID);
				if (!d[ID].empty())
				{
					printf("%0.0lf\n", d[ID].front());
					d[ID].pop_front();
				}
				else
					printf("NULL\n");
			}
		}
	}
	return 0;
}