#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#define endl '\n'
using namespace std;

int N;
vector<string> v;
vector<int> alpha;

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	alpha.resize(26);

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int powh = pow(10, (v[i].length() - 1));
		for (int j = 0; j < v[i].length(); j++)
		{
			alpha[v[i][j] - 'A'] += powh / pow(10, j);
		}
	}

	int sum = 0;
	sort(alpha.begin(), alpha.end(), desc);

	int a = 0;
	for (int i = 9; i > 0; i--)
	{
		sum += alpha[a] * i;
		a++;
	}

	cout << sum << endl;

	return 0;
}