#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int arr[45];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < num + 1; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	cout << arr[num] << endl;
	return 0;
}