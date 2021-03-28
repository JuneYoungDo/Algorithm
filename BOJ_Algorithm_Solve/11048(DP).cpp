#include<iostream>
#define endl '\n'
using namespace std;

int N, M;
int map[1001][1001] = { 0, };

int CheckMax(int x, int y, int z);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int max = CheckMax(map[i - 1][j - 1], map[i][j - 1], map[i - 1][j]);
			map[i][j] += max;
		}
	}

	cout << map[N][M] << endl;

	return 0;
}

int CheckMax(int x, int y, int z)
{
	int max = 0;
	if (max < x)max = x;
	if (max < y)max = y;
	if (max < z)max = z;

	return max;
}
