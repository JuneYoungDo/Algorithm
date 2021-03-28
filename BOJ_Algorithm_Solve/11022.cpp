#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];
	int* arr1 = new int[n];
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr1[i] = a;
		arr2[i] = b;
		arr[i] = a + b;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Case #" << i + 1 << ": " << arr1[i] << " + " << arr2[i] << " = " << arr[i] << '\n';
	}

	return 0;
}