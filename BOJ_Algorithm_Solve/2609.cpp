#include <iostream>
using namespace std;
#define endl '\n';

int a, b;
int gcd, lcm;

int getGcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int getLcm(int a, int b, int c)
{
	return a * b / c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	gcd = getGcd(a, b);
	lcm = getLcm(a, b, gcd);

	cout << gcd << ' ' << lcm << endl;

	return 0;
}