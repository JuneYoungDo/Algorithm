#include<iostream>
using namespace std;
#define endl '\n';

int n, k;
int health[51];
bool visit[51];
int ans;
int weight = 500;

void dfs(int tmp)
{
	if (tmp == n)
		ans++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				if (weight + health[i] >= 500)
				{
					weight += health[i];
					dfs(tmp + 1);
					weight -= health[i];
					visit[i] = false;
				}
				else
					visit[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> health[i];
		health[i] -= k;
	}
	dfs(0);

	cout << ans << endl;

	return 0;
}