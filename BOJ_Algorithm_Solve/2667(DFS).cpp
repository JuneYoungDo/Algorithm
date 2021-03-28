#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int N;
int cnt;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
string map[26];
bool visit[26][26];
vector<int> ans;

void dfs(int startX, int startY);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '1' && visit[i][j] == false)
			{
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;


	return 0;
}

void dfs(int startX, int startY)
{
	visit[startX][startY] = true;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nextX = startX + dx[i];
		int nextY = startY + dy[i];
		if ((0 <= nextX && nextX < N) && (0 <= nextY && nextY < N))
			if (map[nextX][nextY] == '1' && visit[nextX][nextY] == false)
				dfs(nextX, nextY);
	}
}