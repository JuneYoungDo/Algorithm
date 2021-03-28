#include<iostream>
#include<string>
#include<math.h>
using namespace std;
#define endl '\n';

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (testcase--)
	{
		int ans = 0;
		int level = 0;
		int maxLevel = 0;
		string s;
		getline(cin, s);

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '[')
			{
				level++;
				if (maxLevel <= level)
					maxLevel = level;
			}
			else
				level--;
		}

		ans = pow(2, maxLevel);

		//		for (int i = 0; i < maxLevel; i++)
		//			ans = ans * 2;

		cout << (int)ans << endl;
	}


	return 0;
}