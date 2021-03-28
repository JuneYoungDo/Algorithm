#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n';

int n, p;
int w, l, goal;
int score;
bool flag;

char scoreC;
string game[1001];

vector<pair<string, char>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p;
	cin >> w >> l >> goal;

	for (int i = 0; i < p; i++)
	{
		string s;
		char c;
		cin >> s >> c;

		v.push_back(make_pair(s, c));
	}

	for (int i = 0; i < n; i++)
	{
		cin >> game[i];
	}

	for (int i = 0; i < n; i++)
	{
		string s = game[i];

		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].first == s)
			{
				scoreC = v[j].second;
				break;
			}
			else
				scoreC = 'L';
		}

		if (scoreC == 'W')
			score += w;

		else
		{
			score -= l;
			if (score < 0)
				score = 0;
		}
		if (score >= goal)
			flag = true;
	}

	if (flag)
		cout << "I AM NOT IRONMAN!!" << endl;
	if (!flag)
		cout << "I AM IRONMAN!!" << endl;

	return 0;
}