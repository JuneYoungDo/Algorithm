#include<iostream>
using namespace std;

int main()
{
	char arr[101];
	cin >> arr;

	for (int i = 1; i < 101; i++)
	{
		if (arr[i - 1] == NULL)
		{
			break;
		}

		cout << arr[i - 1];

		if (i % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}