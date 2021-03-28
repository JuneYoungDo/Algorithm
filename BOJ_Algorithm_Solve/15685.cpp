#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define endl '\n'

struct curve
{
	int y, x;
};

curve dir[4] = { {0,1},{-1,0},{0,-1},{1,0} };

int n;
int x, y, d, g;
int map[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int ans = 0;

	while (n--)
	{
		cin >> x >> y >> d >> g;

		//	매번 새로운 벡터로 새로운 드래곤커브 생성
		vector<int> curve;
		curve.push_back(d);

		//	규칙성을 통한 방향 벡터 채우기
		for (int i = 0; i < g; i++)
		{
			for (int j = curve.size() - 1; j >= 0; j--)
			{
				curve.push_back((curve[j] + 1) % 4);
			}
		}
		map[y][x] = 1;

		//	현재위치 이동
		for (int i = 0; i < curve.size(); i++)
		{
			y = y + dir[curve[i]].y;
			x = x + dir[curve[i]].x;

			map[y][x] = 1;
		}

	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[j][i] && map[j + 1][i] && map[j + 1][i + 1] && map[j][i + 1])
				ans++;
		}
	}

	cout << ans << endl;

	return 0;
}