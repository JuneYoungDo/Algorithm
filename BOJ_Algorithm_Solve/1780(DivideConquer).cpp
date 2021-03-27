#include<iostream>
#define endl '\n'
#define max 3000
using namespace std;

int n;
int map[max][max];
int cnt[3];

bool check(int a, int b, int n);
void resize(int a, int b, int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	resize(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;

	return 0;
}

bool check(int a, int b, int n)
{
	for (int i = a; i < a + n; i++)
	{
		for (int j = b; j < b + n; j++)
		{
			if (map[a][b] != map[i][j])
				return false;
		}
	}
	return true;
}

void resize(int a, int b, int n)
{
	if (check(a, b, n) == true)
	{
		if (map[a][b] == -1)cnt[0]++;
		else if (map[a][b] == 0)cnt[1]++;
		else cnt[2]++;
		return;
	}

	int div = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			resize(a + (i * div), b + (j * div), div);
		}
	}
}