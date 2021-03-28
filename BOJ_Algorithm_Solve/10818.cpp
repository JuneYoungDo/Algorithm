#include<iostream>
using namespace std;

int main()
{
	int num;
	int max = -1000000;
	int min = 1000000;
	int n;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		if (n >= max)
		{
			max = n;
		}
		if (n <= min)
		{
			min = n;
		}
	}
	cout << min << " " << max << endl;
	return 0;
}