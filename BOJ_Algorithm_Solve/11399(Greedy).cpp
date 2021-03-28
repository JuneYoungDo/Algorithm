#include<iostream>
#include<algorithm>
using namespace std;

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
	sort(arr, arr + n);

	int* arrt = new int[n];
	arrt[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		arrt[i] = arrt[i - 1] + arr[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + arrt[i];
	}
	cout << sum << '\n';

	return 0;
}