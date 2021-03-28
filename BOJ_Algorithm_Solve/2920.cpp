#include<iostream>
using namespace std;

int main()
{
	int a = 0;
	int d = 0;
	int arr[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < 8; j++)
	{
		if (j + 1 == arr[j])
		{
			a++;
		}
		else if (j + 1 == arr[7 - j])
		{
			d++;
		}
	}
	if (a == 8)
	{
		cout << "ascending" << endl;
	}
	else if (d == 8)
	{
		cout << "descending" << endl;
	}
	else
	{
		cout << "mixed" << endl;
	}
	return 0;
}