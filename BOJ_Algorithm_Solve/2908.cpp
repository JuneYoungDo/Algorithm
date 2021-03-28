#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int a1, b1;
	int a2, b2;
	int c, d, e;
	int f, g, h;

	a1 = a;
	b1 = b;

	c = a1 / 100;
	d = (a1 % 100) / 10;
	e = (a1 % 100) % 10;

	f = b1 / 100;
	g = (b1 % 100) / 10;
	h = (b1 % 100) % 10;

	a2 = e * 100 + d * 10 + c;
	b2 = h * 100 + g * 10 + f;

	if (a2 > b2)
	{
		cout << a2 << endl;
	}
	else
	{
		cout << b2 << endl;
	}

	return 0;
}