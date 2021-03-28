#include<iostream>
using namespace std;

int main()
{
	int arr[3];
	int arr1[2];

	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> arr1[i];
	}

	int min = arr[0];
	int min1 = arr1[0];

	for (int i = 0; i < 3; i++)
	{
		if (min >= arr[i])
		{
			min = arr[i];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (min1 >= arr1[i])
		{
			min1 = arr1[i];
		}
	}

	cout << min + min1 - 50 << endl;


	return 0;
}