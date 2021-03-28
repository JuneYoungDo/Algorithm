#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = a + b;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}