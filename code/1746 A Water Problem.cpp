#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < 23; i++)
		{
			cin >> s;
		}

		if (s == ".....#..........#.......")
		{
			cout << "Black King" << endl;
		}
		else
		{
			cout << "Red General" << endl;
		}
	}
	return 0;
}