#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'

int map[501][501];
bool visit[501][501];
int mx[4] = { -1,1,0,0 };
int my[4] = { 0,0,-1,1 };
int ans;
int ans2;
int row, column;

//	중복을 허용하는 길이 4의 dfs
void dfs(int x, int y, int sum, int length)
{
	if (length >= 4)
	{
		if (sum >= ans)
			ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int dx = x + mx[i];
		int dy = y + my[i];

		if (dx < 0 || dx >= row || dy < 0 || dy >= column)
			continue;
		else
			if (!visit[dx][dy])
			{
				visit[dx][dy] = true;
				dfs(dx, dy, sum + map[dx][dy], length + 1);
				visit[dx][dy] = false;		// 중복허용 해줘야함
			}
	}
}

//		ㅗ,ㅜ,ㅏ,ㅓ 모양 3*3 맵에서 8가지 경우의 수 (노가다)
int special(int x, int y)
{
	vector<int> arr;
	arr.resize(8);
	arr[0] = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
	arr[1] = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
	arr[2] = map[x + 2][y] + map[x + 2][y + 1] + map[x + 2][y + 2] + map[x + 1][y + 1];
	arr[3] = map[x][y + 2] + map[x + 1][y + 2] + map[x + 2][y + 2] + map[x + 1][y + 1];

	arr[4] = map[x + 1][y + 1] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 2];
	arr[5] = map[x + 1][y + 1] + map[x][y + 1] + map[x + 1][y] + map[x + 2][y + 1];
	arr[6] = map[x + 1][y + 1] + map[x + 1][y] + map[x + 2][y + 1] + map[x + 1][y + 2];
	arr[7] = map[x + 1][y + 1] + map[x][y + 1] + map[x + 2][y + 1] + map[x + 1][y + 2];

	sort(arr.begin(), arr.end());

	return arr[7];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> column;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			cin >> map[i][j];

	// ㅗ,ㅜ,ㅓ,ㅏ 뺀 경우
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			visit[i][j] = true;
			dfs(i, j, map[i][j], 1);
			visit[i][j] = false;
		}
	//	ㅗ,ㅜ,ㅓ,ㅏ 의 경우
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			if (i + 2 >= row || j + 2 >= column)
				continue;
			else
			{
				int tmp = special(i, j);
				if (tmp >= ans2)
					ans2 = tmp;
			}
		}
	if (ans >= ans2)
		cout << ans << endl;
	else
		cout << ans2 << endl;

	return 0;
}