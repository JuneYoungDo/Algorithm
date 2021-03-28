#include<iostream>
using namespace std;

int main()
{
	int num1;
	int num2;
	int arr[10000];

	cin >> num1 >> num2;
	for (int i = 0; i < num1; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < num1; j++)
	{
		if (arr[j] < num2)
		{
			cout << arr[j] << ' ';
		}
	}
	cout << endl;



	return 0;
}