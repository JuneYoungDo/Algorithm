#include<iostream>
#include<algorithm>
using namespace std;

int bs(int target, int* arr, int size)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (left + right + 1) / 2;
		if (arr[mid] == target)
			return 1;
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}

	int target;
	cin >> target;
	int* arr2 = new int[target];

	for (int i = 0; i < target; i++)
	{
		int x;
		cin >> x;
		arr2[i] = x;
	}

	sort(arr, arr + n);

	for (int i = 0; i < target; i++)
	{
		cout << bs(arr2[i], arr, n) << '\n';
	}

	return 0;
}