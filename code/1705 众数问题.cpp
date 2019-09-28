#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, m, max = 0;
	map <int, int> number;
	map <int, int>::iterator iter;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> m;
			iter = number.find(m);
			if (iter == number.end())
			{
				number.insert(map <int, int>::value_type(m, 1));
			}
			else
				iter->second++;
		}
		for (iter = number.begin(); iter != number.end(); iter++)
		{
			if (iter->second > max)
			{
				max = iter->second;
				m = iter->first;
			}
		}
		cout << m << ' ' << max << endl;
		number.clear();
		max = 0;
	}
	return 0;
}