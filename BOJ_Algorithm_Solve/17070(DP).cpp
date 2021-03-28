#include<iostream>
#define endl '\n';
using namespace std;

struct movePive
{
	int y, x;
};

int n;
int home[17][17];	// 0 : 빈칸, 1 : 벽
movePive moveDir[3] = { {0,1},{1,0},{1,1} };	// 가로 세로 대각
int answer;

void pipeMoving(int y, int x, int shape)	// shape : 파이프 모양 ( 0: 가로, 1: 세로, 2: 대각)
{
	if (y == n - 1 && x == n - 1)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((shape == 0 && i == 1) || (shape == 1 && i == 0))	// 가로일때 세로 불가, 세로일때 가로 불가
			continue;

		// 이동
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;

		if (nextY >= n || nextX >= n || home[nextY][nextX] == 1)	// 밖으로 나가거나 벽일 경우
			continue;

		if (i == 2 && (home[y][nextX] == 1 || home[nextY][x] == 1))		// 대각일 경우 주변 벽 비어있어야함
			continue;

		pipeMoving(nextY, nextX, i);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> home[i][j];

	pipeMoving(0, 1, 0);

	cout << answer << endl;

	return 0;
}