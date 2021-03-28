#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (b < 45)
	{
		a = a - 1;
		if (a == -1)
		{
			cout << "23 " << b + 60 - 45 << endl;
		}
		else
		{
			cout << a << ' ' << b + 60 - 45 << endl;
		}
	}
	else if (b >= 45)
	{
		cout << a << " " << b - 45 << endl;
	}


	return 0;
}