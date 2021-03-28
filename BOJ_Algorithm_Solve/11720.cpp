#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	char arr;
	int sum = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr;
		sum += (arr - '0');
	}
	cout << sum << endl;

	return 0;
}