#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}