#include<iostream>
using namespace std;

int main()
{
	int arr[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	int max = arr[0];
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	cout << max << endl;

	for (int i = 0; i < 9; i++)
	{
		if (max == arr[i])
		{
			cout << i + 1 << endl;;
		}
	}


	return 0;
}