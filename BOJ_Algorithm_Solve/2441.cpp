#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < num - i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}