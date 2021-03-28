#include<iostream>
#define endl '\n'
using namespace std;

int msize;
int map[101][101];
int answer[101][101];
bool visit[101];

void dfs(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> msize;
	for (int i = 0; i < msize; i++)
	{
		for (int j = 0; j < msize; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < msize; i++)
	{
		dfs(i);
		for (int j = 0; j < msize; j++)
		{
			if (visit[j] == true)
				answer[i][j] = 1;
			else
				answer[i][j] = 0;
		}
		for (int j = 0; j < msize; j++)
			visit[j] = false;
	}

	for (int i = 0; i < msize; i++)
	{
		for (int j = 0; j < msize; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void dfs(int index)
{
	for (int i = 0; i < msize; i++)
	{
		if (map[index][i] == 1 && visit[i] == false)
		{
			visit[i] = true;
			dfs(i);
		}
	}
}