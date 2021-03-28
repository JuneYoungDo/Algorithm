#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> node[1024];

int main()
{
	int depth;
	cin >> depth;

	int level = 2;

	int num = pow(2, depth) - 1;

	for (int i = 1; i < num + 1; i++)
	{
		int a;
		cin >> a;

		node[i].push_back(a);
	}
	cout << node[num / 2 + 1].front() << endl;

	node[num / 2 + 1].pop_back();
	node[num / 2 + 1].push_back(0);

	while (1)
	{
		if (depth - level == -1)
		{
			break;
		}
		for (int i = 1; i < num + 1; i++)
		{
			int b = pow(2, depth - level);
			if (i % b == 0 && node[i].front() != 0)
			{
				cout << node[i].front() << ' ';
				node[i].pop_back();
				node[i].push_back(0);
			}
		}
		cout << endl;
		level++;
	}

	return 0;
}