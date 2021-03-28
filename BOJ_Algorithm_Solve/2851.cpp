#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int sum = 0;
	int beforesum = 0;
	int diff = 100;

	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int a = 0;
	while (1)
	{
		beforesum = sum;
		sum = sum + v[a];
		if (sum > 100)
		{
			if (abs(beforesum - 100) < abs(sum - 100))
			{
				cout << beforesum << '\n';
				break;
			}
			else if (abs(beforesum - 100) > abs(sum - 100))
			{
				cout << sum << '\n';
				break;
			}
			else
			{
				cout << sum << '\n';
				break;
			}
		}
		a++;
		if (a > 10)
		{
			cout << sum << '\n';
			break;
		}
	}

	return 0;
}