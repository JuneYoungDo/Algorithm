#include<iostream>
#define endl '\n'
using namespace std;

int pibo0[50] = { 0, };
int pibo1[50] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pibo0[0] = 1;
	pibo0[1] = 0;

	pibo1[0] = 0;
	pibo1[1] = 1;

	int T;
	cin >> T;
	while (T--)
	{
		int num;
		cin >> num;

		for (int i = 2; i <= num; i++)
		{
			pibo0[i] = pibo0[i - 1] + pibo0[i - 2];
			pibo1[i] = pibo1[i - 1] + pibo1[i - 2];
		}

		if (num == 0)
			cout << 1 << ' ' << 0 << endl;
		else if (num == 1)
			cout << 0 << ' ' << 1 << endl;
		else
		{
			cout << pibo0[num] << ' ' << pibo1[num] << endl;
		}
	}
	return 0;
}