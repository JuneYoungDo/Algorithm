# include<iostream>
using namespace std;

int main()
{
	int a, b, v;
	int ans = 0;
	cin >> a >> b >> v;

	ans = (v - b - 1) / (a - b);

	cout << ans + 1 << endl;

}