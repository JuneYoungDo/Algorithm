#include<iostream>
#include<vector>
using namespace std;

vector<int> Tn;

int Eureka(int num)
{
	int cnt = 0;
	for (int j = 1; j < num; j++)
	{
		for (int k = 1; k < num; k++)
		{
			for (int m = 1; m < num; m++)
			{
				if (Tn[j] + Tn[k] + Tn[m] == num)
				{
					cnt = 1;
					return cnt;
				}
			}
		}
	}
	return cnt;
}

int main()
{
	Tn.push_back(0);
	for (int i = 1; i < 1000; i++)
	{
		Tn.push_back(i * (i + 1) / 2);
	}
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cout << Eureka(a) << '\n';
	}

	return 0;
}